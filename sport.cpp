#include <iostream>
#include <string>
using namespace std;

// Your declarations and implementations would go here
// --------DECLARATIONS START HERE-------
class Sport {
public:
    Sport(string n);
    string name() const;
    virtual bool isOutdoor() const;
    virtual string icon() const = 0;
    virtual ~Sport();
private:
    string m_name;
};

class Snowboarding : public Sport {
public:
    Snowboarding(string n);
    string icon() const;
    ~Snowboarding();
};

class Biathlon : public Sport {
public:
    Biathlon(string n, double d);
    string icon() const;
    ~Biathlon();
private:
    double distance;
    
};

class FigureSkating : public Sport {
public:
    FigureSkating(string n);
    bool isOutdoor() const;
    string icon() const;
    ~FigureSkating();
private:
};

// ---------IMPLEMENTATIONS START HERE---------
Sport::Sport(string n) : m_name(n) {}
string Sport::name() const { return m_name; }
bool Sport::isOutdoor() const { return true; }
Sport::~Sport() {}

Snowboarding::Snowboarding(string n) : Sport(n) {}
string Snowboarding::icon() const { return "a snowboarder in a tucked grab"; }
Snowboarding::~Snowboarding() { cout << "Destroying the Snowboarding object named " << name() << "." << endl; }

Biathlon::Biathlon(string n, double d) : Sport(n), distance(d) {}
string Biathlon::icon() const { return "a skier with a rifle"; }
Biathlon::~Biathlon() { cout << "Destroying the Biathlon object named " << name() << ", distance " << distance << " km." << endl; }

FigureSkating::FigureSkating(string n) : Sport(n) {}
bool FigureSkating::isOutdoor() const { return false; }
string FigureSkating::icon() const { return "a skater in a scratch spin";}
FigureSkating::~FigureSkating() { cout << "Destroying the FigureSkating object named " << name() << "." << endl; }

void display(const Sport* sp)
{
    cout << sp->name() << " is ";
    if (sp->isOutdoor())
        cout << "an outdoor sport ";
    else
        cout << "an indoor sport ";
    cout << "with an icon showing " << sp->icon() << "." << endl;
}

int main()
{
    Sport* sports[4];
    sports[0] = new Snowboarding("Women's halfpipe");
      // Biathlon events have a distance in kilometers
    sports[1] = new Biathlon("Men's pursuit", 12.5);
    sports[2] = new Biathlon("Women's sprint", 7.5);
    sports[3] = new FigureSkating("Ice dance");

    cout << "Here are the sports." << endl;
    for (int k = 0; k < 4; k++)
        display(sports[k]);

      // Clean up the sports before exiting
    cout << "Cleaning up." << endl;
    for (int k = 0; k < 4; k++)
        delete sports[k];
}
