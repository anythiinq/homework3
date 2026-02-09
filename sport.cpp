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
