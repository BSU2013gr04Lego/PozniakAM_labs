/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3.VM;

import java.io.IOException;
import java_lab_3.VM.*;
import java_lab_3.terms.*;
import java.util.ArrayList;
import java_lab_3.utils.Serializer;
import java.nio.ByteBuffer;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;

import java_lab_3.TEObject;

/**
 *
 * @author krucios
 */
public class Machine extends TEObject {
    public int mem_size = 30000;
    
    private int[] memory;
    private int I_M;
    
    private ArrayList<Term> program;
    private int I_P;
    
    public Machine() {
        memory = new int[mem_size];
        program = new ArrayList<Term>();
        I_M = 0;
    }
    
    /********************************************************
     * 
     *  Main methods:
     *  - void execute()
     *  - void loadFromFile(String file_name)
     *  - void saveToFile(String file_name)
     * 
     ********************************************************/
    
    public void execute() throws VMException, IOException {
        for (; I_P < program.size(); I_P++) {
            program.get(I_P).execute(this);
            try {
                this.saveToFile("auto_save.bfvm");
            } catch (IOException err) {
                System.err.println("Can't create auto_save.bfvm");
            }
        }
    }
    
    public void loadFromFile(String file_name) 
           throws IOException, VMException {
        Path path = Paths.get(file_name);
        this.deserialize(Files.readAllBytes(path));
    }
    
    public void saveToFile(String file_name) throws IOException {
        Path path = Paths.get(file_name);
        byte[] serialized_vm = this.serialize(); 
        Files.write(path, serialized_vm);
    }
    
    // ===== Memory Control
    public void set_I_M(int I_M) throws VMException {
        if (I_M < 0 || mem_size < I_M)
            throw new VMException("Range error");
        
        this.I_M = I_M;
    }
    
    public int get_I_M() {
        return I_M;
    }
    
    public void setCurMem(int val) throws VMException {
        if (val < 0 || 255 < val)
            throw new VMException("Incorrect value. Value must be in range [0 .. 255]");
        
        memory[I_M] = val;
    }
    
    public int getCurMem() {
        return memory[I_M];
    }
    
    // ==== Program Control
    public void setCurTerm(Term term) {
        program.set(I_P, term);
    }
    
    public Term getCurTerm() {
        return program.get(I_P);
    }
    
    public void set_I_P(int I_P) throws VMException {
        if (I_P < 0 || program.size() < I_P)
            throw new VMException("Index out of avaliable range");
        
        this.I_P = I_P;
    }
    
    public int get_I_P() {
        return I_P;
    }
    
    public ArrayList<Term> getProgram() {
        return program;
    }
    
    /*************************************************
    * LAB 3.1   Regular expression usage
    *************************************************/
    private boolean verifyProgram(String program) {
        Pattern p = Pattern.compile("[<>+-.,\\[\\]]*");
        Matcher m = p.matcher(program);
        return m.matches();
    }
    
    public void downloadProgram(String program) throws VMException {
        if (this.verifyProgram(program)) {
            for(int i = 0; i < program.length(); ++i) {
                switch(program.charAt(i)) {
                    case '>': // code 0
                        this.program.add(new TNext(i));
                        break;
                    case '<': // code 1
                        this.program.add(new TPrev(i));
                        break;
                    case '+': // code 2
                        this.program.add(new TInc(i));
                        break;
                    case '-': // code 3
                        this.program.add(new TDec(i));
                        break;
                    case '.': // code 4
                        this.program.add(new TPrint(i));
                        break;
                    case ',': // code 5
                        this.program.add(new TInput(i));
                        break;
                    case '[': // code 6
                        this.program.add(new TStCycle(i));
                        break;
                    case ']': // code 7
                        this.program.add(new TEnCycle(i));
                        break;
                    default:
                        throw new VMException("Unknown symbol " + program.charAt(i));
                }
            }
        } else {
            throw new VMException("Bad programm");
        }
    }
    
    /************************************
     * LAB 3.2 SERIALIZATION
     ************************************/
    public byte[] serialize() {
        ByteBuffer ans = ByteBuffer.allocate(mem_size * 4 + 4 * 4 + program.size() * (4 + 1));
        // Serialize mem_size
        ans.putInt(mem_size);
        // Serialize memory[]
        for (int i = 0; i < mem_size; ++i) {
            ans.putInt(memory[i]);
        }
        // Serialize I_M
        ans.putInt(I_M);
        // Serialize program.size
        ans.putInt(program.size());
        // Serialize program
        for (int i = 0; i < program.size(); ++i) {
            if (program.get(i) instanceof TNext) {
                ans.put((byte) 0x0);
            } else if (program.get(i) instanceof TPrev) {
                ans.put((byte) 0x1);
            } else if (program.get(i) instanceof TInc) {
                ans.put((byte) 0x2);
            } else if (program.get(i) instanceof TDec) {
                ans.put((byte) 0x3);
            } else if (program.get(i) instanceof TPrint) {
                ans.put((byte) 0x4);
            } else if (program.get(i) instanceof TInput) {
                ans.put((byte) 0x5);
            } else if (program.get(i) instanceof TStCycle) {
                ans.put((byte) 0x6);
            } else if (program.get(i) instanceof TEnCycle) {
                ans.put((byte) 0x7);
            }
            
            ans.putInt(program.get(i).getPos());
        }
        // Serialize I_P
        ans.putInt(I_P);
        return ans.array();
    }
    
    public void deserialize(byte[] saved) throws VMException {
        int position = 0;
        // Load mem_size
        this.mem_size = (saved[position++] << 24) + (saved[position++] << 16) + 
                        (saved[position++] << 8) + (saved[position++]);
        // Load memory[]
        this.memory = new int[this.mem_size];
        for (int i = 0; i < this.mem_size; ++i) {
            this.memory[i] = (saved[position++] << 24) + (saved[position++] << 16) + 
                             (saved[position++] << 8) + (saved[position++]);
        }
        // Load I_M
        this.I_M = (saved[position++] << 24) + (saved[position++] << 16) + 
                   (saved[position++] << 8) + (saved[position++]);
        // Load program.size
        int prog_size = (saved[position++] << 24) + (saved[position++] << 16) + 
                        (saved[position++] << 8) + (saved[position++]);
        // Load programm
        this.program.clear();
        for (int i = 0; i < prog_size; ++i) {
            byte term_type = saved[position++];
            int term_position = (saved[position++] << 24) + (saved[position++] << 16) + 
                                (saved[position++] << 8) + (saved[position++]);
            assert (term_position == i);
            switch (term_type) {
                case 0:
                    this.program.add(new TNext(i));
                    break;
                case 1:
                    this.program.add(new TPrev(i));
                    break;
                case 2:
                    this.program.add(new TInc(i));
                    break;
                case 3:
                    this.program.add(new TDec(i));
                    break;
                case 4:
                    this.program.add(new TPrint(i));
                    break;
                case 5:
                    this.program.add(new TInput(i));
                    break;
                case 6:
                    this.program.add(new TStCycle(i));
                    break;
                case 7:
                    this.program.add(new TEnCycle(i));
                    break;
                default:
                    throw new VMException("Unknown term type");
            }
        }
        // Load I_P
        this.I_P = (saved[position++] << 24) + (saved[position++] << 16) + 
                   (saved[position++] << 8) + (saved[position++]);
    }
    
    /************************************
     * LAB 3.3 TRANSITIVE COMPARISON
     ************************************/
    @Override
    public boolean isEqual(TEObject obj) {
        Machine that = (Machine) obj;
        if (that == null) {
            return false;
        }
        boolean ans = true;
        if (this.mem_size != that.mem_size)
            return false;
        for (int i = 0; i < this.mem_size; ++i) {
            if (this.memory[i] != that.memory[i])
                return false;
        }
        if (this.I_M != that.I_M)
            return false;
        if (this.program.size() != that.program.size())
            return false;
        for (int i = 0; i < this.program.size(); ++i) {
            if (!TEObject.isEqual(this.program.get(i), that.program.get(i)))
                return false;
        }
        if (this.I_P != that.I_P)
            return false;
        return super.isEqual(that);
    }
}
