#include <iostream>
#include <string>

using namespace std;

class Translator
{
private:
    string m_name;

    Translator(const Translator &obj) {};
    Translator& operator=(const Translator &obj) {};

protected:
    virtual int calculateCost(int distance_km) const = 0;
    virtual float calculateTime(int distance_km) const = 0;

public:

    Translator(string name = "Parovozik")
    {
        m_name = name;
    };
    virtual ~Translator() {};

    void claculateCharacteristics(int distance, int &cost, float &time)
    {
        cost = calculateCost(distance);
        time = calculateTime(distance);
    };

    string getName() const
    {
        return m_name;
    }
};

class Plane : public Translator
{
private:
    int speed;
    int cost;
protected:
    virtual int calculateCost(int distance_km) const
    {
        if (distance_km < 500)
        {
            return distance_km * 2 * cost;
        }
        else
        {
            return distance_km * cost;
        }
    }

    virtual float calculateTime(int distance_km) const
    {
        return (float)distance_km / speed;
    }
public:
    Plane(int speed = 500, int cost_per_km = 1, string s = "Default plane") :
        Translator(s)
    {
        this->speed = speed;
        this->cost = cost_per_km;
    }

    ~Plane() {};
};

class Train : public Translator
{
private:
    int speed;
    int cost;
protected:
    virtual int calculateCost(int distance_km) const
    {
        return distance_km * cost;
    }

    virtual float calculateTime(int distance_km) const
    {
        return (float)distance_km / speed;
    }
public:
    Train(int speed = 90, int cost_per_km = 3, string s = "Default train") :
        Translator(s)
    {
        this->speed = speed;
        this->cost = cost_per_km;
    }

    ~Train() {};
};

class Bus : public Translator
{
private:
    int speed;
    int cost;
    int hotel_cost;
    bool is_driver_pare;
protected:
    virtual int calculateCost(int distance_km) const
    {
        return distance_km * cost + hotel_cost * (int)(calculateTime(distance_km) / 24);
    }

    virtual float calculateTime(int distance_km) const
    {
        float ans_time = 0;
        if (is_driver_pare)
        {
            while (distance_km > speed * 17)
            {
                distance_km -= speed * 17;
                ans_time += 24;
            }
            ans_time += (float)distance_km / speed;
        }
        else
        {
            while (distance_km > speed * 12)
            {
                distance_km -= speed * 12;
                ans_time += 24;
            }
            ans_time += (float)distance_km / speed;
        }
        return ans_time;
    }
public:
    Bus(bool is_driver_pare = false, int speed = 70, int hotel_cost = 10, int cost_per_km = 5, string s = "Default bus") :
        Translator(s)
    {
        this->is_driver_pare = is_driver_pare;
        this->speed = speed;
        this->cost = cost_per_km;
        this->hotel_cost = hotel_cost;
    }

    ~Bus() {};
};

int main()
{
    Translator **transport = new Translator*[6];
    transport[0] = new Train(90, 3, "Blue train");
    transport[1] = new Train(45, 10, "Bad train");
    transport[2] = new Plane(500, 12, "Democraty delivers");
    transport[3] = new Plane(113, 4, "Air bicykle");
    transport[4] = new Bus(false, 60, 10, 5, "GrodnoOblTrans");
    transport[5] = new Bus(true, 999, 20, 10, "S Veterkom");

    int dist;

    cout << "Enter distance: ";
    cin >> dist;

    for (int i = 0; i < 6; ++i)
    {
        int cost = 0;
        float time = 0;
        transport[i]->claculateCharacteristics(dist, cost, time);
        cout << endl << transport[i]->getName() << endl
             << "    cost : " << cost << endl
             << "    time : " << time << endl;
    }

    return 0;
}
