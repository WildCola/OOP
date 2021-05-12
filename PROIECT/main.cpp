#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>

using namespace std;

fstream ulog;
fstream plog;
fstream flog;
fstream adlog;
fstream th;

char gotoXY(int x, int y);
void startmenu();
void ulogin(char name[]);
void alogin(char name[]);
void badlogin();
void userlog();
void checkprem();
void premlogin();
void askprem();


char gotoXY(int x, int y) //functie adaptata dupa cea gasita la: http://www.cplusplus.com/forum/general/56892/
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD CursorPosition;
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

char getOption()
{
    char x;
	cin>>x;
	return x;
}

string getLogname()
{
    string name;
    cin>>name;
    return name;
}

string getLogpass()
{
    string pass;
    cin>>pass;
    return pass;
}



class year
{
public:
    virtual void returntime()=0;//aflu timpul curent https://stackoverflow.com/questions/8343676/how-to-get-current-date-and-time
};



class film:public year
{
private:
    string title;
    string director;
    string genre;
    unsigned int ratings;
    float* rate;
    float avgrate;
    double budget;
    unsigned int year;

public:

    string getTitle()
    {
        return this->title;
    }

    string getDirector()
    {
        return this->director;
    }

    string getGenre()
    {
        return this->genre;
    }

    float getRating()
    {
        return this->avgrate;
    }

    double getBudget()
    {
        return this->budget;
    }

    int getYear()
    {
        return this->year;
    }

    float* getRatings()
    {
        return this->rate;
    }

    int getRate()
    {
        return this->ratings;
    }

    void setTitle(string s)
    {
        this->title = s;
    }

    void setDirector(string s)
    {
        this->director = s;
    }

    void setGenre(string s)
    {
        this->genre = s;
    }

    void setBudget(double b)
    {
        this->budget = b;
    }

    void setYear(unsigned int y)
    {
        this->year = y;
    }


    film()
    {
        this->title = "Title Placeholder";

        this->director = "Director Placeholder";

        this->genre = "Genre Placeholder";

        this->ratings = 0;

        this->rate = NULL;

        this->avgrate = 0;

        this->budget = 0;

        this->year = 0;
    }

    film(string title, string director, string genre, unsigned int ratings, float* rate, double budget, unsigned int year)
    {
        this->title = title;

        this->director = director;

        this->genre = genre;

        this->ratings = ratings;

        this->rate = new float[ratings];
        double sumrate=0;
        for(int i=0; i<ratings; ++i)
        {
            this->rate[i] = rate[i];
            sumrate+=rate[i];
        }

        if(ratings)
            this->avgrate = sumrate/ratings;
        else
            this->avgrate = 0;

        this->budget = budget;

        this->year = year;
    }

    film(string title, string director, string genre)
    {
        this->title = title;

        this->director = director;

        this->genre = genre;

        this->ratings = 0;

        this->rate = NULL;

        this->avgrate = 0;

        this->budget = 0;

        this->year = 0;
    }

    film(const film& u)
    {

        this->title = u.title;

        this->director = u.director;

        this->genre = u.genre;

        this->ratings = u.ratings;

        this->rate = new float[this->ratings];
        for(int i=0;i<this->ratings;++i)
            this->rate[i] = u.rate[i];

        this->avgrate = u.avgrate;

        this->budget = u.budget;

        this->year = u.year;
    }

    film& operator=(const film &u)
    {
        if(this!= &u)
        {
            if(this->rate!=NULL)
                delete[] this->rate;

            this->title = u.title;

            this->director = u.director;

            this->genre = u.genre;

            this->ratings = u.ratings;

            this->rate = new float[this->ratings];
            for(int i=0;i<this->ratings;++i)
                this->rate[i] = u.rate[i];

            this->avgrate = u.avgrate;

            this->budget = u.budget;

            this->year = u.year;
        }
        return *this;
    }

    bool operator==(const film& u)
    {
        if(this->title == u.title && this->director == u.director && this->year == u.year)
            return 1;
        return 0;
    }

    bool operator<(const film& u)
    {
        if(this->avgrate < u.avgrate)
            return 1;
        return 0;
    }

    bool operator>(const film& u)
    {
        if(this->avgrate > u.avgrate)
            return 1;
        return 0;
    }

    bool operator<=(const film& u)
    {
        if(this->avgrate <= u.avgrate)
            return 1;
        return 0;
    }

    bool operator>=(const film& u)
    {
        if(this->avgrate >= u.avgrate)
            return 1;
        return 0;
    }

    const film& operator++()
    {
        this->ratings++;
        float* newrate = new float[this->ratings];
        for(int i=0; i<this->ratings-1; ++i)
            newrate[i] = this->rate[i];
        newrate[this->ratings-1] = 5;
        this->avgrate = (this->avgrate*(this->ratings-1) + 5)/this->ratings;
        this->rate = newrate;

        return *this;
    }

    const film& operator--()
    {
        this->ratings++;
        float* newrate = new float[this->ratings];
        for(int i=0; i<this->ratings-1; ++i)
            newrate[i] = this->rate[i];
        newrate[this->ratings-1] = 0;
        this->avgrate = (this->avgrate*(this->ratings-1) + 0)/this->ratings;
        this->rate = newrate;

        return *this;
    }

    const film operator++(int)
    {
        film aux(*this);
        this->ratings++;
        this->rate = new float[this->ratings];
        for(int i=0; i<this->ratings-1; ++i)
            this->rate[i] = aux.rate[i];
        this->rate[this->ratings-1] = 5;
        this->avgrate = (this->avgrate*(this->ratings-1) + 5)/this->ratings;

        return aux;
    }

    const film operator--(int)
    {
        film aux(*this);
        this->ratings++;
        this->rate = new float[this->ratings];
        for(int i=0; i<this->ratings-1; ++i)
            this->rate[i] = aux.rate[i];
        this->rate[this->ratings-1] = 0;
        this->avgrate = (this->avgrate*(this->ratings-1) + 0)/this->ratings;

        return aux;
    }

    film operator+(float x)
    {
        film aux(*this);
        aux.ratings++;
        aux.rate = new float[aux.ratings];
        for(int i=0; i<this->ratings; ++i)
            aux.rate[i] = this->rate[i];
        aux.rate[this->ratings] = x;
        aux.avgrate = (aux.avgrate*(aux.ratings-1) + x)/aux.ratings;

        return aux;
    }

    friend film operator+(int x, film u)
    {
        film aux(u);
        aux.ratings++;
        aux.rate = new float[aux.ratings];
        for(int i=0; i<u.ratings; ++i)
            aux.rate[i] = u.rate[i];
        aux.rate[u.ratings] = x;
        aux.avgrate = (aux.avgrate*(aux.ratings-1) + x)/aux.ratings;
        return aux;
    }


    film operator-(int x)
    {
        film aux(*this);
        if(aux.ratings>x)
        {
        aux.ratings-=x;
        aux.rate = new float[aux.ratings];
        double newavg=0;
        for(int i=0; i<aux.ratings; ++i)
        {
            aux.rate[i] = this->rate[i];
            newavg+=aux.rate[i];
        }
        aux.avgrate = newavg/aux.ratings;
        }
        if(aux.ratings==x)
        {
            aux.ratings=0;
            aux.rate = NULL;
            aux.avgrate = 0;
        }
        return aux;
    }

    friend film operator-(int x, film u)
    {
        film aux(u);
        if(aux.ratings<x && x-aux.ratings <= aux.ratings)
        {
            aux.ratings = x-aux.ratings;
            aux.rate = new float[aux.ratings];
            double newavg=0;
            for(int i=0; i<aux.ratings; ++i)
            {
                aux.rate[i] = u.rate[i];
                newavg+=aux.rate[i];
            }
            aux.avgrate = newavg/aux.ratings;
        }
        if(aux.ratings==x)
        {
            aux.ratings=0;
            aux.rate = NULL;
            aux.avgrate = 0;
        }
        return aux;
    }

    explicit operator float()
    {
        return (float)this->avgrate;
    }

    explicit operator int()
    {
        return (int)this->year;
    }

    float& operator[](int index)
    {
        return this->rate[index];
    }

    friend istream& operator>>(istream& in,film& u);
    friend ostream& operator<<(ostream& out, const film& u);

    ~film()
    {
        if(this->rate!=NULL)
            delete[] rate;
    }

    bool recommend(film u)
    {
        if(u.genre.compare(this->genre) == 0)
            if(u.avgrate - this->avgrate >= -0.5)
                return 1;
        return 0;
    }

    void returntime(){
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        int year = aTime->tm_year + 1900;
        cout<<"\n"<<this->title<<" came out "<<year-this->year<<" years ago";
    }

};

istream& operator>>(istream& in,film& u)
{
    cout<<"\nTitle: ";
    in>>u.title;
    cout<<"\nDirector: ";
    in>>u.director;
    cout<<"\nGenre: ";
    in>>u.genre;
    cout<<"\nNumber of ratings: ";
    in>>u.ratings;
    if(u.ratings)
    {
        cout<<"\nRatings: ";
        u.rate=new float[u.ratings];
        double avg=0;
        for(int i=0;i<u.ratings;++i)
        {
            in>>u.rate[i];
            avg+=u.rate[i];
        }
        u.avgrate=avg/u.ratings;
    }

    else
    {
        u.rate = NULL;
        u.avgrate=0;
    }

    cout<<"\nBudget: ";
    in>>u.budget;
    cout<<"\nYear: ";
    in>>u.year;

    return in;
}

ostream& operator<<(ostream& out,const film& u)
{
    out<<"\nTitle: "<<u.title;
    out<<"\nDirector: "<<u.director;
    out<<"\nGenre: "<<u.genre;
    out<<"\nRating: "<<u.avgrate;
    out<<"\nBudget: $"<<fixed<<setprecision(2)<<u.budget;
    out<<"\nYear: "<<u.year;
    return out;
}

class advertised:public film
{
private:
    int startdate[8];
    int stopdate[8];
public:
    int* getStartdate()
    {
        return this->startdate;
    }

    int* getStopdate()
    {
        return this->stopdate;
    }

    advertised():film()
    {
        for(int i=0;i<8;++i)
        {
            this->startdate[i]=0;
            this->stopdate[i]=0;
        }
    }

    advertised(string title, string director, string genre, unsigned int ratings, float* rate, double budget, unsigned int year, int startdate[8], int stopdate[8]):film(title, director, genre, ratings, rate, budget, year)
    {
        for(int i=0;i<8;++i)
        {
            this->startdate[i]=startdate[i];
            this->stopdate[i]=stopdate[i];
        }
    }

    advertised(string title, string director, string genre, int startdate[8], int stopdate[8]):film(title, director, genre)
    {
        for(int i=0;i<8;++i)
        {
            this->startdate[i]=startdate[i];
            this->stopdate[i]=stopdate[i];
        }
    }

    advertised(const advertised& a):film(a)
    {
        for(int i=0;i<8;++i)
        {
            this->startdate[i]=a.startdate[i];
            this->stopdate[i]=a.stopdate[i];
        }
    }

    advertised& operator=(const advertised& a)
    {
        if(this!=&a)
        {
            film::operator=(a);
            for(int i=0;i<8;++i)
            {
                this->startdate[i]=a.startdate[i];
                this->stopdate[i]=a.stopdate[i];
            }
        }
        return *this;
    }

    friend istream& operator>>(istream& in, advertised& a)
    {
        in>>(film&)a;
        cout<<"\nStart: ";
        for(int i=0;i<8;++i)
        {
            char g;
            g=getch();
            cout<<g - '0';
            a.startdate[i]=int(g-'0');
            if(i==1 || i==3)
                cout<<"/";
        }
        cout<<"\nStop: ";
        for(int i=0;i<8;++i)
        {
            char g;
            g=getch();
            cout<<g - '0';
            a.stopdate[i]=int(g - '0');
            if(i==1 || i==3)
                cout<<"/";
        }

        return in;
    }

    friend ostream& operator<<(ostream& out, const advertised& a)
    {
        out<<(film&)a;
        out<<"\nStart: ";
        for(int i=0;i<8;++i)
        {
            cout<<a.startdate[i];
            if(i==1 || i==3)
                cout<<"/";
        }
        out<<"\nStop: ";
        for(int i=0;i<8;++i)
        {
            cout<<a.stopdate[i];
            if(i==1 || i==3)
                cout<<"/";
        }
        return out;
    }
};

class user
{
private:
    char* username;
    string parola;
    int nrnume;
    string* nume;
    char gen;
    int filmevazute;
    bool card;
    int* numerecard;
    int* dataexp;
    vector<film> vazut;

public:

    char* getUsername()
    {
        return this->username;
    }

    string getParola()
    {
        return this->parola;
    }

    string* getNume()
    {
        if(this->nume!=NULL)
            return this->nume;
    }

    int getNrnume()
    {
        return this->nrnume;
    }

    char getGen()
    {
        return this->gen;
    }

    bool getCard()
    {
        return this->card;
    }

    int* getNrcard()
    {
        if(this->numerecard!=NULL)
            return this->numerecard;
    }

    int* getData()
    {
        if(this->dataexp!=NULL)
            return this->dataexp;
    }

    int getFilme()
    {
        return this->filmevazute;
    }

    void setUsername(char* u)
    {
        this->username = new char[strlen(u)+1];
        for(int i=0;i<strlen(u);++i)
        strcpy(this->username,u);
    }

    void setParola(string p)
    {
        this->parola=p;
    }

    void setNumereCard(int* nr)
    {
        for(int i=0;i<16;++i)
            this->numerecard[i]=nr[i];
    }

    void setData(int m, int y)
    {
        this->dataexp[0]=m;
        this->dataexp[1]=y;
    }

    user()
    {
        this->username=new char[strlen("user")+1];
        strcpy(this->username,"user");

        this->parola = "0000";

        this->nrnume = 0;

        this->nume = NULL;

        this->gen = 'o';

        this->filmevazute = 0;

        this->card = 0;

        this->numerecard = NULL;

        this->dataexp = NULL;
    }

    user(char* username, string parola, int nrnume, string* nume, char gen, bool card, int* numerecard, int* dataexp)
    {
        this->username = new char[strlen(username)+1];
        strcpy(this->username,username);

        this->parola = parola;

        this->nrnume = nrnume;

        this->nume = new string[nrnume];
        for(int i=0; i<nrnume; ++i)
            this->nume[i] = nume[i];

        this->gen = gen;

        this->filmevazute = 0;

        this->card = card;

        if(this->card==1)
        {
            this->numerecard = new int[16];
            for(int i=0;i<16;++i)
                this->numerecard[i] = numerecard[i];

            this->dataexp = new int[2];
            this->dataexp[0] = dataexp[0];
            this->dataexp[1] = dataexp[1];
        }
        else
        {
            this->numerecard=NULL;
            this->dataexp=NULL;
        }
    }

    user(char* username, string parola)
    {

        this->username = new char[strlen(username)+1];
        strcpy(this->username,username);

        this->parola = parola;

        this->nrnume = 0;

        this->nume = NULL;

        this->gen = 'o';

        this->filmevazute = 0;

        this->card = 0;

        this->numerecard = NULL;

        this->dataexp = NULL;
    }

    user(const user& u)
    {

        this->username = new char[strlen(u.username)+1];
        strcpy(this->username,u.username);

        this->parola = u.parola;

        this->nrnume = u.nrnume;

        if(this->nrnume)
            this->nume = new string[this->nrnume];
                for(int i=0; i<this->nrnume; ++i)
                    this->nume[i] = u.nume[i];

        this->gen = u.gen;

        this->filmevazute = u.filmevazute;

        this->card = u.card;

        if(this->card == 1)
        {
            this->numerecard = new int[16];
            for(int i=0;i<16;++i)
                this->numerecard[i] = u.numerecard[i];

            this->dataexp = new int[2];
            this->dataexp[0] = u.dataexp[0];
            this->dataexp[1] = u.dataexp[1];
        }

        for(auto i=u.vazut.begin(); i!=u.vazut.end();++i)
            this->vazut.push_back(*i);
    }

    user& operator=(const user &usr)
    {
        if(this!= &usr)
        {
            if(this->username!=NULL)
                delete[] this->username;

            if(this->nume!=NULL)
                delete[] this->nume;

            if(this->numerecard!=NULL)
                delete[] this->numerecard;

            if(this->dataexp!=NULL)
                delete[] this->dataexp;

            this->username = new char(strlen(usr.username)+1);
            strcpy(this->username, usr.username);

            this->parola = usr.parola;

            this->nrnume = usr.nrnume;

            this->nume = new string[this->nrnume];
            for(int i=0; i<this->nrnume; ++i)
                this->nume[i] = usr.nume[i];

            this->gen = usr.gen;

            this->filmevazute = usr.filmevazute;

            this->card = usr.card;

            this->numerecard = new int[16];
            for(int i=0;i<16;++i)
                this->numerecard[i] = usr.numerecard[i];

            this->dataexp = new int[2];
            this->dataexp[0] = usr.dataexp[0];
            this->dataexp[1] = usr.dataexp[1];

            this->vazut = usr.vazut;
        }
        return *this;
    }

    bool operator==(const user& u)
    {
        if(strcmp(this->username, u.username)==0)
            return 1;
        return 0;
    }

    bool operator<(const user& u)
    {
        if(this->filmevazute < u.filmevazute)
            return 1;
        return 0;
    }

    bool operator<=(const user& u)
    {
        if(this->filmevazute <= u.filmevazute)
            return 1;
        return 0;
    }

    bool operator>(const user& u)
    {
        if(this->filmevazute > u.filmevazute)
            return 1;
        return 0;
    }

    bool operator>=(const user& u)
    {
        if(this->filmevazute >= u.filmevazute)
            return 1;
        return 0;
    }

    explicit operator int()
    {
        return (int)this->filmevazute;
    }

    string& operator[](int index)
    {
        return this->nume[index];
    }

    friend istream& operator>>(istream& in,user& u);
    friend ostream& operator<<(ostream& out, const user& u);

    ~user()
    {
        if(username != NULL)
            delete[] username;
        if(numerecard != NULL)
            numerecard = NULL;
        if(dataexp != NULL)
            dataexp = NULL;
        vazut.clear();
    }

    virtual bool verifylogin(char* username, string password)
    {
        if(strcmp(this->username, username) == 0 && password.compare(this->parola)  == 0)
            return 1;
        else
            return 0;
    }

    void addFilm(film f)
    {
        this->filmevazute++;
        this->vazut.push_back(f);
    }

};

istream& operator>>(istream& in,user& u)
{
    cout<<"\nUsername: ";
    in>>u.username;
    cout<<"\nPassword: ";
    in>>u.parola;
    cout<<"\nNumber of names: ";
    in>>u.nrnume;
    u.nume = new string[u.nrnume];
    for(int i=0;i<u.nrnume;++i)
    {
        cout<<"Nume "<<i+1<<": ";
        in>>u.nume[i];
    }
    cout<<"\nGender:\n1.Male 2.Female 3.Other: ";
    int g;
    in>>g;
    if(g==1)
        u.gen = 'm';
    if(g==2)
        u.gen = 'f';
    if(g==3)
        u.gen = 'o';
    cout<<"\nDo you want to add your credit card information?\n1.Yes 2.No: ";
    in>>g;
    if(g==2)
    {
        u.card=0;
        u.numerecard=NULL;
        u.dataexp=NULL;
    }

    if(g==1)
    {
        u.numerecard = new int[16];
        cout<<"\nEnter the numbers on the card: ";
        for(int i=0; i<16; ++i)
        {
            g = getch();
            cout<<g - '0';
            if((i+1)%4==0)
                cout<<" ";
            u.numerecard[i]=g - '0';
        }
        u.dataexp = new int[2];
        cout<<"\nEnter the expiration date: ";
        cout<<"\nLuna: ";
        cin>>u.dataexp[0];
        cout<<"\nAnul: ";
        cin>>u.dataexp[1];

    }
    return in;
}

ostream& operator<<(ostream& out,const user& u)
{
    out<<"\nUsername: "<<u.username;
    out<<"\nPassword: "<<u.parola;
    out<<"\nNumber of names: "<<u.nrnume;
    if(u.nrnume)
        for(int i=0;i<u.nrnume;++i)
            out<<"\n"<<u.nume[i];
    out<<"\nGender: "<<u.gen;
    if(u.card)
    {
        out<<"\nCard info: ";
        for(int i=0;i<16;++i)
        {
            out<<u.numerecard;
            if((i+1)%4==0)
                out<<" ";
        }
        out<<"\nExpiration date: "<<u.dataexp[0]<<u.dataexp[1];
    }
    out<<"\nMovies seen: "<<u.filmevazute;
    int c=1;
    for(auto i = u.vazut.begin(); i!=u.vazut.end(); ++i)
    {
        film f=*i;
        out<<"\n"<<c<<". "<<f.getTitle()<<" ";
        c++;
    }

    return out;
}

class premium:public user
{
private:
    int start[8];
    int months;
public:
    premium():user()
    {
        for(int i=0;i<8;++i)
            start[i]=0;
        months=0;
    }

    premium(char* username, string parola, int nrnume, string* nume, char gen, bool card, int* numerecard, int* dataexp, int start[8], int months):user(username, parola, nrnume, nume, gen, card, numerecard, dataexp)
    {
        for(int i=0;i<8;++i)
            this->start[i]=start[i];
        this->months=months;
    }

    premium(char* username, string parola, int start[8], int months):user(username, parola)
    {
        for(int i=0;i<8;++i)
            this->start[i]=start[i];
        this->months=months;
    }

    premium(const premium& p):user(p)
    {
        for(int i=0;i<8;++i)
            this->start[i]=p.start[i];
        this->months=p.months;
    }

    premium& operator=(const premium& p)
    {
        if(this!=&p)
        {
            user::operator=(p);
            for(int i=0;i<8;++i)
                this->start[i]=p.start[i];
            this->months=p.months;
        }
        return *this;
    }

    int* getStart()
    {
        return this->start;
    }

    int getMonths()
    {
        return this->months;
    }

    friend istream& operator>>(istream& in, premium& p)
    {
        in>>(user&)p;
        cout<<"\nSubscribtion date: ";
        for(int i=0;i<8;++i)
        {
            char g;
            g=getch();
            cout<<g - '0';
            p.start[i]=int(g-'0');
            if(i==1 || i==3)
                cout<<"/";
        }
        cout<<"\nMonths subscribed: ";
        in>>p.months;
        return in;
    }

    friend ostream& operator<<(ostream& out, const premium& p)
    {
        out<<(user&)p;
        out<<"\nSubscribtion date: ";
        for(int i=0;i<8;++i)
        {
            out<<p.start[i];
            if(i==1 || i==3)
                cout<<"/";
        }
        out<<"\nMonths subscribed: ";
        out<<p.months;
        return out;
    }

    void returntime()
    {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        int curmonth = aTime->tm_mon + 1;
        int curyear = aTime->tm_year + 1900;
        int year = this->start[4]*1000+this->start[5]*100+this->start[6]*10+this->start[7];
        int month = this->start[2]*10+this->start[3];
        int expyear = year;
        int expmonth = month+this->months;
        if(expmonth>12)
        {
            expyear+=expmonth/12;
            expmonth%=12;
        }
        cout<<"\nYour subscription will expire in ";
        cout<<expyear-year<<" years and ";
        cout<<expmonth-month<<" months";
    }
};

class admin
{
private:
    char* username;
    string parola;
    int nrnume;
    string* nume;
    char gen;
    unsigned int grad;

public:

     char* getUsername()
    {
        return this->username;
    }

    string getParola()
    {
        return this->parola;
    }

    string* getNume()
    {
        if(this->nume!=NULL)
            return this->nume;
    }

    void setUsername(char* u)
    {
        this->username = new char[strlen(u)+1];
        for(int i=0;i<strlen(u);++i)
        strcpy(this->username,u);
    }

    void setParola(string p)
    {
        this->parola=p;
    }


    admin()
    {
        this->username=new char[strlen("user")+1];
        strcpy(this->username,"user");

        this->parola = "0000";

        this->nrnume = 0;

        this->nume = NULL;

        this->gen = 'o';

        this->grad = 0;
    }

    admin(char* username, string parola, int nrnume, string* nume, char gen, int grad)
    {
        this->username = new char[strlen(username)+1];
        strcpy(this->username,username);

        this->parola = parola;

        this->nrnume = nrnume;

        this->nume = new string[nrnume];
        for(int i=0; i<nrnume; ++i)
            this->nume[i] = nume[i];

        this->gen = gen;

        this->grad = grad;
    }

    admin(char* username, string parola)
    {

        this->username = new char[strlen(username)+1];
        strcpy(this->username,username);

        this->parola = parola;

        this->nrnume = 0;

        this->nume = NULL;

        this->gen = 'o';

        this->grad = 0;
    }

    admin(const admin& u)
    {

        this->username = new char[strlen(u.username)+1];
        strcpy(this->username,u.username);

        this->parola = u.parola;

        this->nrnume = u.nrnume;

        if(this->nrnume)
            this->nume = new string[this->nrnume];
                for(int i=0; i<this->nrnume; ++i)
                    this->nume[i] = u.nume[i];

        this->gen = u.gen;

        this->grad = u.grad;
    }

    admin& operator=(const admin &usr)
    {
        if(this!= &usr)
        {
            if(this->username!=NULL)
                delete[] this->username;

            if(this->nume!=NULL)
                delete[] this->nume;

            this->username = new char(strlen(usr.username)+1);
            strcpy(this->username, usr.username);

            this->parola = usr.parola;

            this->nrnume = usr.nrnume;

            this->nume = new string[this->nrnume];
            for(int i=0; i<this->nrnume; ++i)
                this->nume[i] = usr.nume[i];

            this->gen = usr.gen;

            this->grad = usr.grad;
        }
        return *this;
    }

    bool operator==(const admin& u)
    {
        if(this->username == u.username)
            return 1;
        return 0;
    }

    bool operator<(const admin& u)
    {
        if(this->grad < u.grad)
            return 1;
        return 0;
    }

    bool operator>(const admin& u)
    {
        if(this->grad > u.grad)
            return 1;
        return 0;
    }

    bool operator<=(const admin& u)
    {
        if(this->grad <= u.grad)
            return 1;
        return 0;
    }

    bool operator>=(const admin& u)
    {
        if(this->grad <= u.grad)
            return 1;
        return 0;
    }

    const admin& operator++()
    {
        this->grad++;
        return *this;
    }

    const admin& operator--()
    {
        if(this->grad)
            this->grad--;
        return *this;
    }

    const admin operator++(int)
    {
        admin aux(*this);
        this->grad++;
        return aux;
    }

    const admin operator--(int)
    {
        admin aux(*this);
        this->grad--;
        return aux;
    }

    admin operator+(int x)
    {
        admin aux(*this);
        aux.grad+=x;
        return aux;
    }

    friend admin operator+(int x, admin u)
    {
        u.grad += x;
        return u;
    }

    admin operator-(int x)
    {
        admin aux(*this);
        if(aux.grad>=x)
            aux.grad-=x;
        else
            aux.grad = 0;
        return aux;
    }

    friend admin operator-(int x, admin u)
    {
        if(x >= u.grad)
            u.grad = x - u.grad;
        else
            u.grad = 0;
        return u;
    }

    explicit operator int()
    {
        return (int)this->grad;
    }

    string& operator[](int index)
    {
        return this->nume[index];
    }

    friend istream& operator>>(istream& in,admin& u);
    friend ostream& operator<<(ostream& out, const admin& u);

    ~admin()
    {
        if(this->username!=NULL)
            delete[] this->username;
        if(this->nume!=NULL)
            delete[] this->nume;
    }

    bool verifylogin(char* username, string password)
    {
        if(strcmp(this->username, username) == 0 && password.compare(this->parola)  == 0)
            return 1;
        else
            return 0;
    }
};

istream& operator>>(istream& in,admin& u)
{
    cout<<"\nUsername: ";
    in>>u.username;
    cout<<"\nPassword: ";
    in>>u.parola;
    cout<<"\nNumber of names: ";
    in>>u.nrnume;
    u.nume = new string[u.nrnume];
    for(int i=0;i<u.nrnume;++i)
    {
        cout<<"Nume "<<i+1<<": ";
        in>>u.nume[i];
    }
    cout<<"\nGender:\n1.Male 2.Female 3.Other: ";
    int g;
    in>>g;
    if(g==1)
        u.gen = 'm';
    if(g==2)
        u.gen = 'f';
    if(g==3)
        u.gen = 'o';

    cout<<"\nRank: ";
    in>>u.grad;
    return in;
}

ostream& operator<<(ostream& out,const admin& u)
{
    out<<"\nUsername: "<<u.username;
    out<<"\nPassword: "<<u.parola;
    out<<"\nNumber of names: "<<u.nrnume;
    if(u.nrnume)
        for(int i=0;i<u.nrnume;++i)
            out<<"\n"<<u.nume[i];
    out<<"\nGender: "<<u.gen;
    out<<"\nRank: "<<u.grad;
    return out;
}


class theme
{
private:
    const string color[16] = {"black", "blue", "green", "aqua", "red", "purple", "yellow", "white", "gray", "light blue", "light green" , "light aqua", "light red", "light purple", "light yellow", "bright white"};
    const int ID;
    int text;
    int background;
    string name;
    int likes;

public:
    static int cont;

    int getText()
    {
        return this->text;
    }

    int getBackground()
    {
        return this->background;
    }

    theme():ID(cont++)
    {
        this->name = "default";
        this->text = 7;
        this->background = 0;
        this->likes = 0;
    }

    theme(string name, int text, int background):ID(cont++)
    {
        this->name = name;
        this->text = text;
        this->background = background;
        this->likes = 0;
    }

    theme(int text, int background):ID(cont++)
    {
        this->name = "Untitled Theme";
        this->text = text;
        this->background = background;
        this->likes = 0;
    }

    theme(const theme& t):ID(t.ID)
    {
        this->name = t.name;
        this->background = t.background;
        this->text = t.text;
        this->likes = t.likes;
    }

    theme& operator=(const theme& t)
    {
        if(this!= &t)
        {
            this->name = t.name;
            this->background = t.background;
            this->text = t.text;
            this->likes = t.likes;
        }
        return *this;
    }

    bool operator==(const theme& t)
    {
        if(this->name == t.name || (this->text == t.text && this->background == t.background))
            return 1;
        return 0;
    }

    bool operator>(const theme& t)
    {
        if(this->likes>t.likes)
            return 1;
        return 0;
    }

    bool operator>=(const theme& t)
    {
        if(this->likes>=t.likes)
            return 1;
        return 0;
    }

    bool operator<(const theme& t)
    {
        if(this->likes<t.likes)
            return 1;
        return 0;
    }

    bool operator<=(const theme& t)
    {
        if(this->likes<=t.likes)
            return 1;
        return 0;
    }

    const theme& operator++()
    {

        this->likes++;
        return *this;
    }

    const theme& operator--()
    {
        this->likes--;
        return *this;
    }

    const theme operator++(int)
    {
        theme aux(*this);
        this->likes++;
        return aux;
    }

    const theme operator--(int)
    {
        theme aux(*this);
        this->likes--;
        return aux;
    }

    theme operator+(int x)
    {
        theme aux(*this);
        aux.likes += x;
        return aux;
    }

    friend theme operator+(int x, theme t)
    {
        t.likes += x;
        return t;
    }

    theme operator-(int x)
    {
        theme aux(*this);
        aux.likes -= x;
        return aux;
    }

    friend theme operator-(int x, theme t)
    {
        t.likes = x-t.likes;
        return t;
    }

    explicit operator int()
    {
        return (int)this->likes;
    }

    string operator[](int index)
    {
        return this->color[index];
    }

    friend istream& operator>>(istream& in,theme& u);
    friend ostream& operator<<(ostream& out, const theme& u);

    ~theme()
    {};

    void changeTheme()
    {
        char b, t;
        stringstream d;
        d<<hex<<this->background;
        d>>hex>>b;
        d<<hex<<this->text;
        d>>hex>>t;
        char col[9];
        strcpy(col, "color ");
        col[6]=b;
        col[7]=t;
        col[8]='\0';
        system(col);
    }

    int colorIndex(string color)
    {
        for(int i=0;i<16;++i)
            if(color == this->color[i])
                return i;
        return -1;
    }

};

istream& operator>>(istream& in,theme& u)
{
    cout<<"\nName: ";
    in>>u.name;
    cout<<"\nColors:\n";
    for(int i=0;i<16;++i)
        cout<<i<<". "<<u.color[i]<<"\n";
    cout<<"\nText color: ";
    in>>u.text;
    cout<<"\nBackgronud color: ";
    in>>u.background;
    return in;
}

ostream& operator<<(ostream& out, const theme& u)
{
    out<<"\nName: "<<u.name;
    out<<"\nText color: "<<u.color[u.text];
    out<<"\nBackgronud color: "<<u.color[u.background];
    out<<"\nNumber of likes: "<<u.likes;
    return out;
}

int theme::cont = 1;

void gooduser(user u);
void goodprem(premium u);
void goodadmin(admin u);
void cataloguser(user u);
void userset(user u);
void premset(premium u);
void addfilm(admin u);
void addad(admin u);
void delfilm(admin u);
void deladd(admin u);
void chthem(admin u);

vector<user> listuser;
vector<premium> listprem;
vector<film> filme;
list<admin> vadmin;
vector<advertised> vad;

int nruseri;
int nradmini;
int nrprem;
int nrfilme;
int nrads;

int main()
{
    th.open("theme.txt", ios::in);
    int tex, bak;
    th>>tex>>bak;
    th.close();
    theme t1(tex, bak);
    t1.changeTheme();
    startmenu();

    return 0;
}

void startmenu()
{
    system("cls");

    cout<<"Welcome to our movie rental service\n";

    cout<<"1. User Log In\n";
    cout<<"2. Create New Account\n";
    cout<<"3. Admin Log In\n";
    cout<<"4. Exit Program\n";
    cout<<"\nChoose any option to continue: ";


    char x;
    x = getOption();
    switch(x)
    {
    case '1':
        checkprem();
        break;

    case '2':
        askprem();
        break;

    case '3':
        alogin("Admin");
        break;

    case '4':
        return;
        break;

    default:
        startmenu();
        break;
    }
}

void createacc(int x)
{
    system("cls");
    cout<<"Fill in your information: ";

    if(x==1)
    {
        while(!listuser.empty())
            listuser.pop_back();

        ulog.open("users.txt", ios::in);
        char readname[20];
        ulog>>nruseri;
        ulog.get();

        for(int i=1; i<=nruseri; ++i)
        {
            char parola[20];
            char gen;
            int nrnume;
            int nrcard[16]={0};
            int dataexp[2]={0};
            bool card;
            string nume[10];
            ulog.get(readname, 20);
            ulog.get();
            ulog.get(parola, 20);
            ulog.get();
            ulog>>nrnume;
            ulog.get();
            for(int i=0;i<nrnume && nrnume!=0;++i)
            {
                char nm[20];
                ulog.get(nm, 20);
                nume[i] = nm;
                ulog.get();
            }
            ulog>>gen;
            ulog.get();
            ulog>>card;
            ulog.get();
            if(card==1)
            {
                for(int i=0;i<16;++i)
                {
                    ulog>>nrcard[i];
                }

                ulog.get();
                ulog>>dataexp[0]>>dataexp[1];
                ulog.get();
            }

            user u(readname, parola, nrnume, nume, gen, card, nrcard, dataexp);
            listuser.push_back(u);
        }
        ulog.close();

        user nou;
        bool ok=1;
        cin>>nou;
        nruseri++;
        for(auto a:listuser)
        {
            if(a == nou)
                ok=0;
        }

        if(ok==1)
        {
            listuser.push_back(nou);

            ulog.open("users.txt", ios::out | ios::trunc);

            ulog<<nruseri<<"\n";
            for(auto a:listuser)
            {
                ulog<<a.getUsername()<<"\n";
                ulog<<a.getParola()<<"\n";
                ulog<<a.getNrnume()<<"\n";

                for(int i=0; i<a.getNrnume(); ++i)
                    ulog<<a[i]<<"\n";
                ulog<<a.getGen()<<"\n";
                ulog<<a.getCard()<<"\n";
                if(a.getCard() == 1)
                {
                    int* numere;
                    numere = a.getNrcard();
                    for(int i=0; i<16; ++i)
                        ulog<<numere[i]<<" ";
                    ulog<<"\n";

                    numere = a.getData();
                    ulog<<numere[0]<<" "<<numere[1]<<"\n";
                }
            }
            ulog.close();
            gooduser(nou);
            return;
        }

        else
        {
            system("cls");
            cout<<"Username taken!\nPress any key to continue: ";
            int y;
            cin>>y;
            createacc(x);
        }
    }

    if(x==2)
    {
        while(!listprem.empty())
            listprem.pop_back();

        plog.open("premium.txt", ios::in);
        char readname[20];
        plog>>nrprem;
        plog.get();

        for(int i=1; i<=nrprem; ++i)
        {
            char parola[20];
            char gen;
            int nrnume;
            int nrcard[16];
            int dataexp[2];
            bool card;
            int start[8];
            int months;
            string nume[10];
            plog.get(readname, 20);
            plog.get();
            plog.get(parola, 20);
            plog.get();
            plog>>nrnume;
            plog.get();
            for(int i=0;i<nrnume;++i)
            {
                char nm[20];
                plog.get(nm, 20);
                nume[i] = nm;
                plog.get();
            }
            plog>>gen;
            plog.get();
            plog>>card;
            plog.get();
            if(card)
            {
                for(int i=0;i<16;++i)
                {
                    plog>>nrcard[i];
                    //cout<<nrcard[i];
                }

                plog.get();
                plog>>dataexp[0]>>dataexp[1];
                plog.get();
            }
            for(int i=0;i<7;++i)
                plog>>start[i];
            plog.get();
            plog>>months;
            plog.get();
            premium u(readname, parola, nrnume, nume, gen, card, nrcard, dataexp, start, months);
            listprem.push_back(u);
        }
        plog.close();

        premium nou;
        bool ok=1;
        cin>>nou;
        nrprem++;
        for(auto a:listprem)
        {
            if(a == nou)
                ok=0;
        }

        if(ok==1)
        {
            listprem.push_back(nou);

            plog.open("premium.txt", ios::out | ios::trunc);

            plog<<nruseri<<"\n";
            for(auto a:listprem)
            {
                plog<<a.getUsername()<<"\n";
                plog<<a.getParola()<<"\n";
                plog<<a.getNrnume()<<"\n";

                for(int i=0; i<a.getNrnume(); ++i)
                    plog<<a[i]<<"\n";
                plog<<a.getGen()<<"\n";
                plog<<a.getCard()<<"\n";
                if(a.getCard() == 1)
                {
                    int* numere;
                    numere = a.getNrcard();
                    for(int i=0; i<16; ++i)
                        plog<<numere[i]<<" ";
                    plog<<"\n";

                    numere = a.getData();
                    plog<<numere[0]<<" "<<numere[1]<<"\n";
                }
                int *start = a.getStart();
                for(int i=0; i<8; ++i)
                    plog<<start[i]<<" ";
                plog<<"\n";
                plog<<a.getMonths()<<"\n";
            }
            plog.close();
            goodprem(nou);
            return;
        }

        else
        {
            system("cls");
            cout<<"Username taken!\nPress any key to continue: ";
            int y;
            cin>>y;
            createacc(x);
        }
    }

}

void askprem()
{
    system("cls");
    cout<<"Select 1 for free account or 2 for premium account\n";
    int x;
    cin>>x;
    if(x==1 || x==2)
        createacc(x);
    else
        askprem();
}

void checkprem()
{
    system("cls");
    cout<<"Select 1 for free account or 2 for premium account\n";
    int x;
    cin>>x;
    if(x==1)
        ulogin("User");
    else
    {
        if(x==2)
            premlogin();
        else
            checkprem();
    }
}

void premlogin()
{
    system("cls");
    cout<<"Log In\n\n";
    cout<<"UserName: \n";
    cout<<"Password: \n";

    while(!listprem.empty())
            listprem.pop_back();

    fstream plog("premium.txt", ios::in);
    char readname[20];
    plog>>nrprem;
    plog.get();

    for(int i=1; i<=nrprem; ++i)
    {
        char parola[20];
        char gen;
        int nrnume;
        int nrcard[16];
        int dataexp[2];
        bool card;
        int start[8];
        int months;
        string nume[10];
        plog.get(readname, 20);
        plog.get();
        plog.get(parola, 20);
        plog.get();
        plog>>nrnume;
        plog.get();
        for(int i=0;i<nrnume;++i)
        {
            char nm[20];
            plog.get(nm, 20);
            nume[i] = nm;
            plog.get();
        }
        plog>>gen;
        plog.get();
        plog>>card;
        plog.get();
        if(card)
        {
            for(int i=0;i<16;++i)
            {
                plog>>nrcard[i];
                //cout<<nrcard[i];
            }

            plog.get();
            plog>>dataexp[0]>>dataexp[1];
            plog.get();
        }
        for(int i=0;i<7;++i)
            plog>>start[i];
        plog.get();
        plog>>months;
        plog.get();
        premium u(readname, parola, nrnume, nume, gen, card, nrcard, dataexp, start, months);
        listprem.push_back(u);
    }
    plog.close();

    gotoXY(10, 2);
    string num;
    num = getLogname();
    int l = num.length();
    char nume[l+1];
    strcpy(nume, num.c_str());
    string parola;
    gotoXY(10, 3);
    parola = getLogpass();
    for(auto a:listprem)
        if(a.verifylogin(nume, parola)==1)
        {
            goodprem(a);
            return;
            int b;
            cin>>b;
            break;
        }
    badlogin();
    getch();
    premlogin();
}

void ulogin(char name[])
{
    system("cls");
    cout<<"Log In\n\n";
    cout<<"UserName: \n";
    cout<<"Password: \n";

    while(!listuser.empty())
       listuser.pop_back();

    ulog.open("users.txt", ios::in);
    char readname[20];
    ulog>>nruseri;
    ulog.get();

    for(int i=1; i<=nruseri; ++i)
    {
        char parola[20];
        char gen;
        int nrnume;
        int nrcard[16]={0};
        int dataexp[2]={0};
        bool card;
        string nume[10];
        ulog.get(readname, 20);
        ulog.get();
        ulog.get(parola, 20);
        ulog.get();
        ulog>>nrnume;
        ulog.get();
        for(int i=0;i<nrnume && nrnume!=0;++i)
        {
            char nm[20];
            nume[i] = nm;
            ulog.get();
        }
        ulog>>gen;
        ulog.get();
        ulog>>card;
        ulog.get();
        if(card==1)
        {
            for(int i=0;i<16;++i)
            {
                ulog>>nrcard[i];
            }

            ulog.get();
            ulog>>dataexp[0]>>dataexp[1];
            ulog.get();
        }

        user u(readname, parola, nrnume, nume, gen, card, nrcard, dataexp);
        listuser.push_back(u);
    }
    ulog.close();

    gotoXY(10, 2);
    string num;
    num = getLogname();
    int l = num.length();
    char nume[l+1];
    strcpy(nume, num.c_str());
    string parola;
    gotoXY(10, 3);
    parola = getLogpass();
    for(auto a:listuser)
        if(a.verifylogin(nume, parola)==1)
        {
            gooduser(a);
            return;
            int b;
            cin>>b;
            break;
        }
    badlogin();
    getch();
    ulogin(name);
}

void alogin(char name[])
{
    system("cls");
    cout<<"Log In\n\n";
    cout<<"UserName: \n";
    cout<<"Password: \n";

    fstream file("admins.txt", ios::in);
    char readname[20];
    file>>nradmini;
    file.get();

    for(int i=1; i<=nradmini; ++i)
    {
        char parola[20];
        char gen;
        int nrnume, grad;
        string nume[10];
        file.get(readname, 20);
        file.get();
        file.get(parola, 20);
        file.get();
        file>>nrnume;
        file.get();
        for(int i=0;i<nrnume;++i)
        {
            char nm[20];
            file.get(nm, 20);
            nume[i] = nm;
            file.get();
        }
        file>>gen;
        file.get();
        file>>grad;
        file.get();

        admin u(readname, parola, nrnume, nume, gen, grad);
        vadmin.push_back(u);
    }
    file.close();

    gotoXY(10, 2);
    string num;
    num = getLogname();
    int l = num.length();
    char nume[l+1];
    strcpy(nume, num.c_str());
    string parola;
    gotoXY(10, 3);
    parola = getLogpass();
    for(auto a:vadmin)
        if(a.verifylogin(nume, parola)==1)
        {
            goodadmin(a);
            return;
            int b;
            cin>>b;
            break;
        }
    badlogin();
    getch();
    alogin(name);
}

void badlogin()
{
    system("cls");
    cout<<"Wrong username or password. Press any key to go back to the log in screen\n";
    cout<<"\n";
}

void gooduser(user u)
{
    system("cls");
    cout<<"Welcome "<<u.getUsername()<<"!";
    cout<<"\n";
    cout<<"1. Film Catalogue\n";
    cout<<"2. Settings\n";
    cout<<"3. Log Out\n";
    int x;
    cin>>x;
    switch(x)
    {
    case 1:
        cataloguser(u);
        break;
    case 2:
        userset(u);
        break;
    case 3:
        startmenu();
        break;
    default:
        gooduser(u);
        break;
    }
}

void userset(user u)
{
    system("cls");
    cout<<"Account Settings\n";
    cout<<"1. Change Username\n";
    cout<<"2. Change Password\n";
    cout<<"3. Change Theme\n";
    cout<<"4. Back\n";

    int x;
    cin>>x;
    switch(x)
    {
    case 1:
    {
        system("cls");
        cout<<"Enter new username: ";
        char newname[21];
        bool ok=1;
        cin>>newname;
        ulog.open("users.txt", ios::in);
        char readname[20];
        ulog>>nruseri;
        ulog.get();
        int nrusr;

        while(!listuser.empty())
            listuser.pop_back();

        for(int i=1; i<=nruseri; ++i)
        {
            char parola[20];
            char gen;
            int nrnume;
            int nrcard[16]={0};
            int dataexp[2]={0};
            bool card;
            string nume[10];
            ulog.get(readname, 20);
            ulog.get();
            ulog.get(parola, 20);
            ulog.get();
            ulog>>nrnume;
            ulog.get();
            for(int i=0;i<nrnume && nrnume!=0;++i)
            {
                char nm[20];
                nume[i] = nm;
                ulog.get();
            }
            ulog>>gen;
            ulog.get();
            ulog>>card;
            ulog.get();
            if(card==1)
            {
                for(int i=0;i<16;++i)
                {
                    ulog>>nrcard[i];
                }

                ulog.get();
                ulog>>dataexp[0]>>dataexp[1];
                ulog.get();
            }
            if(strcmp(newname, readname)==0)
                ok=0;
            user us(readname, parola, nrnume, nume, gen, card, nrcard, dataexp);
            listuser.push_back(us);
            if(us==u)
                nrusr=i-1;
        }
        ulog.close();

        if(ok==0)
        {
            cout<<"\nUsername already taken\n";
            system("pause");
            userset(u);
        }
        else
        {
            listuser[nrusr].setUsername(newname);
            ulog.open("users.txt", ios::out | ios::trunc);

            ulog<<nruseri<<"\n";
            for(auto a:listuser)
            {
                ulog<<a.getUsername()<<"\n";
                ulog<<a.getParola()<<"\n";
                ulog<<a.getNrnume()<<"\n";

                for(int i=0; i<a.getNrnume(); ++i)
                    ulog<<a[i]<<"\n";
                ulog<<a.getGen()<<"\n";
                ulog<<a.getCard()<<"\n";
                if(a.getCard() == 1)
                {
                    int* numere;
                    numere = a.getNrcard();
                    for(int i=0; i<16; ++i)
                        ulog<<numere[i]<<" ";
                    ulog<<"\n";

                    numere = a.getData();
                    ulog<<numere[0]<<" "<<numere[1]<<"\n";
                }
            }
            ulog.close();
            cout<<"\nUsername updated\n";
            system("pause");
            userset(u);
        }
        break;
    }
    case 2:
    {
        system("cls");
        cout<<"Enter new password: ";
        char newpass[21];
        cin>>newpass;
        ulog.open("users.txt", ios::in);
        char readname[20];
        ulog>>nruseri;
        ulog.get();
        int nrusr;

        while(!listuser.empty())
            listuser.pop_back();

        for(int i=1; i<=nruseri; ++i)
        {
            char parola[20];
            char gen;
            int nrnume;
            int nrcard[16]={0};
            int dataexp[2]={0};
            bool card;
            string nume[10];
            ulog.get(readname, 20);
            ulog.get();
            ulog.get(parola, 20);
            ulog.get();
            ulog>>nrnume;
            ulog.get();
            for(int i=0;i<nrnume && nrnume!=0;++i)
            {
                char nm[20];
                nume[i] = nm;
                ulog.get();
            }
            ulog>>gen;
            ulog.get();
            ulog>>card;
            ulog.get();
            if(card==1)
            {
                for(int i=0;i<16;++i)
                {
                    ulog>>nrcard[i];
                }

                ulog.get();
                ulog>>dataexp[0]>>dataexp[1];
                ulog.get();
            }
            user us(readname, parola, nrnume, nume, gen, card, nrcard, dataexp);
            listuser.push_back(us);
            if(us==u)
                nrusr=i-1;
        }
        ulog.close();

        listuser[nrusr].setParola(newpass);
        ulog.open("users.txt", ios::out | ios::trunc);

        ulog<<nruseri<<"\n";
        for(auto a:listuser)
        {
            ulog<<a.getUsername()<<"\n";
            ulog<<a.getParola()<<"\n";
            ulog<<a.getNrnume()<<"\n";

            for(int i=0; i<a.getNrnume(); ++i)
                ulog<<a[i]<<"\n";
            ulog<<a.getGen()<<"\n";
            ulog<<a.getCard()<<"\n";
            if(a.getCard() == 1)
            {
                int* numere;
                numere = a.getNrcard();
                for(int i=0; i<16; ++i)
                    ulog<<numere[i]<<" ";
                ulog<<"\n";

                numere = a.getData();
                ulog<<numere[0]<<" "<<numere[1]<<"\n";
            }
        }
        ulog.close();
        cout<<"\nPassword updated\n";
        system("pause");
        userset(u);
        break;
    }

    case 3:
    {
        system("cls");
        cout<<"Choose theme\n";
        theme t;
        cin>>t;
        t.changeTheme();
        system("pause");
        userset(u);
        break;
    }


    case 4:
    {
        gooduser(u);
        break;
    }

    default:
    {
        userset(u);
        break;
    }
    }
}

void premset(premium u)
{
    system("cls");
    cout<<"Account Settings\n";
    cout<<"1. Change Username\n";
    cout<<"2. Change Password\n";
    cout<<"3. Change Theme\n";
    cout<<"4. Check Membership\n";
    cout<<"5. Back\n";

    int x;
    cin>>x;
    switch(x)
    {
    case 1:
    {
        system("cls");
        cout<<"Enter new username: ";
        char newname[21];
        bool ok=1;
        cin>>newname;
        plog.open("premium.txt", ios::in);
        char readname[20];
        plog>>nrprem;
        plog.get();
        int nrusr;

        while(!listprem.empty())
            listprem.pop_back();

        for(int i=1; i<=nrprem; ++i)
        {
            char parola[20];
            char gen;
            int nrnume;
            int nrcard[16]={0};
            int dataexp[2]={0};
            bool card;
            int start[8];
            int months;
            string nume[10];
            plog.get(readname, 20);
            plog.get();
            plog.get(parola, 20);
            plog.get();
            plog>>nrnume;
            plog.get();
            for(int i=0;i<nrnume && nrnume!=0;++i)
            {
                char nm[20];
                nume[i] = nm;
                ulog.get();
            }
            plog>>gen;
            plog.get();
            plog>>card;
            plog.get();
            if(card==1)
            {
                for(int i=0;i<16;++i)
                {
                    plog>>nrcard[i];
                }

                plog.get();
                plog>>dataexp[0]>>dataexp[1];
            }
            plog.get();
            for(int i=0;i<7;++i)
                plog>>start[i];
            plog.get();
            plog>>months;
            plog.get();
            if(strcmp(newname, readname)==0)
                ok=0;
            premium us(readname, parola, nrnume, nume, gen, card, nrcard, dataexp, start, months);
            listprem.push_back(us);
            if(us==u)
                nrusr=i-1;
        }
        plog.close();

        if(ok==0)
        {
            cout<<"\nUsername already taken\n";
            system("pause");
            premset(u);
        }
        else
        {
            listprem[nrusr].setUsername(newname);
            plog.open("premium.txt", ios::out | ios::trunc);

            plog<<nrprem<<"\n";
            for(auto a:listprem)
            {
                plog<<a.getUsername()<<"\n";
                plog<<a.getParola()<<"\n";
                plog<<a.getNrnume()<<"\n";

                for(int i=0; i<a.getNrnume(); ++i)
                    plog<<a[i]<<"\n";
                plog<<a.getGen()<<"\n";
                plog<<a.getCard()<<"\n";
                if(a.getCard() == 1)
                {
                    int* numere;
                    numere = a.getNrcard();
                    for(int i=0; i<16; ++i)
                        plog<<numere[i]<<" ";
                    plog<<"\n";

                    numere = a.getData();
                    plog<<numere[0]<<" "<<numere[1]<<"\n";
                }
                int *start = a.getStart();
                for(int i=0; i<8; ++i)
                    plog<<start[i]<<" ";
                plog<<"\n";
                plog<<a.getMonths()<<"\n";
            }
            plog.close();
            cout<<"\nUsername updated\n";
            system("pause");
            premset(u);
        }
        break;
    }
    case 2:
    {
        system("cls");
        cout<<"Enter new password: ";
        char newname[21];
        cin>>newname;
        plog.open("premium.txt", ios::in);
        char readname[20];
        plog>>nrprem;
        plog.get();
        int nrusr;

        while(!listprem.empty())
            listprem.pop_back();

        for(int i=1; i<=nrprem; ++i)
        {
            char parola[20];
            char gen;
            int nrnume;
            int nrcard[16]={0};
            int dataexp[2]={0};
            bool card;
            int start[8];
            int months;
            string nume[10];
            plog.get(readname, 20);
            plog.get();
            plog.get(parola, 20);
            plog.get();
            plog>>nrnume;
            plog.get();
            for(int i=0;i<nrnume && nrnume!=0;++i)
            {
                char nm[20];
                nume[i] = nm;
                ulog.get();
            }
            plog>>gen;
            plog.get();
            plog>>card;
            plog.get();
            if(card==1)
            {
                for(int i=0;i<16;++i)
                {
                    plog>>nrcard[i];
                }

                plog.get();
                plog>>dataexp[0]>>dataexp[1];
            }
            plog.get();
            for(int i=0;i<7;++i)
                plog>>start[i];
            plog.get();
            plog>>months;
            plog.get();
            premium us(readname, parola, nrnume, nume, gen, card, nrcard, dataexp, start, months);
            listprem.push_back(us);
            if(us==u)
                nrusr=i-1;
        }
        plog.close();

        listprem[nrusr].setParola(newname);
        plog.open("premium.txt", ios::out | ios::trunc);

        plog<<nrprem<<"\n";
        for(auto a:listprem)
        {
            plog<<a.getUsername()<<"\n";
            plog<<a.getParola()<<"\n";
            plog<<a.getNrnume()<<"\n";

            for(int i=0; i<a.getNrnume(); ++i)
                plog<<a[i]<<"\n";
            plog<<a.getGen()<<"\n";
            plog<<a.getCard()<<"\n";
            if(a.getCard() == 1)
            {
                int* numere;
                numere = a.getNrcard();
                for(int i=0; i<16; ++i)
                    plog<<numere[i]<<" ";
                plog<<"\n";

                numere = a.getData();
                plog<<numere[0]<<" "<<numere[1]<<"\n";
            }
        }
        plog.close();
        cout<<"\nPassword updated\n";
        system("pause");
        premset(u);
        break;
    }
    case 3:
    {
        system("cls");
        cout<<"Choose theme\n";
        theme t;
        cin>>t;
        t.changeTheme();
        system("pause");
        premset(u);
        break;
    }
    case 4:
    {
         system("cls");
         u.returntime();
         cout<<"\n";
         system("pause");
         premset(u);
         break;
    }
    case 5:
    {
        goodprem(u);
        break;
    }

    default:
    {
        premset(u);
        break;
    }
    }
}

void cataloguser(user u)
{
    system("cls");
    cout<<"Recommended:\n";
    while(!filme.empty())
       filme.pop_back();


    while(!vad.empty())
       vad.pop_back();
    char title[21];
    char director[21];
    char genre[21];
    char aux[21];
    int i=0;
    unsigned int ratings;
    float* rate;
    double budget;
    unsigned int year;
    int startdate[8];
    int stopdate[8];

    adlog.open("ads.txt", ios::in);
    adlog>>nrads;
    adlog.get();
    for(i=1; i<=nrads; ++i)
    {
        adlog.get(title, 20);
        cout<<title<<"\n";
        adlog.get();
        adlog.get(director, 20);
        adlog.get();
        adlog.get(genre, 20);
        adlog.get();
        adlog>>ratings;
        adlog.get();
        rate = new float[ratings+1];
        for(int j=0;j<ratings; ++j)
        {
            float r;
            adlog>>r;
            rate[j]=r;
        }
        adlog.get();
        adlog>>budget;
        adlog.get();
        adlog>>year;
        adlog.get();
        adlog.get(aux, 20);
        adlog.get();
        for(int j=0; j<8; ++j)
        {
            startdate[j]=int(aux[j]-'0');
        }
        adlog.get(aux, 20);
        adlog.get();
        for(int j=0; j<8; ++j)
        {
            stopdate[j]=int(aux[j]-'0');
        }

        advertised f(title, director, genre, ratings, rate, budget, year, startdate, stopdate);
        vad.push_back(f);
    }
    adlog.close();

    cout<<"\nFilm catalogue:\n";
    flog.open("films.txt", ios::in);
    flog>>nrfilme;
    flog.get();
    for(i=1; i<=nrfilme; ++i)
    {
        flog.get(title, 20);
        cout<<i<<". "<<title<<"\n";
        flog.get();
        flog.get(director, 20);
        flog.get();
        flog.get(genre, 20);
        flog.get();
        flog>>ratings;
        flog.get();
        rate = new float[ratings+1];
        for(int j=0;j<ratings; ++j)
        {
            float r;
            flog>>r;
            rate[j]=r;
        }
        flog.get();
        flog>>budget;
        flog.get();
        flog>>year;
        flog.get();
        film f(title, director, genre, ratings, rate, budget, year);
        filme.push_back(f);
    }
    flog.close();
    cout<<"\n";
    cout<<"Choose a movie to see more about it or '0' to go back: ";
    int x;
    cin>>x;
    if(x==0 || x>nrfilme)
        startmenu();
    else
    {
        system("cls");
        cout<<"Title: "<<filme[x-1].getTitle()<<"\n";
        cout<<"Director: "<<filme[x-1].getDirector()<<"\n";
        cout<<"Genre: "<<filme[x-1].getGenre()<<"\n";
        cout<<"Rating: "<<filme[x-1].getRating()<<"\n";
        cout<<"Budget: "<<fixed<<filme[x-1].getBudget()<<"\n";
        cout<<"Realease year: "<<filme[x-1].getYear();
        filme[x-1].returntime();
        cout<<"\n\n";
        cout<<"Choose a number between '1' and '5' to rate the movie or '0' to go back: ";
        float y;
        cin>>y;
        if(y>=1 && y<=5)
        {
            filme[x-1]=filme[x-1]+y;
            flog.open("films.txt", ios::out | ios::trunc);
            flog<<nrfilme;
            flog<<"\n";
            for(int k=0; k<nrfilme; ++k)
            {
                flog<<filme[k].getTitle()<<"\n";
                flog<<filme[k].getDirector()<<"\n";
                flog<<filme[k].getGenre()<<"\n";
                ratings=filme[k].getRate();
                rate=filme[k].getRatings();
                flog<<ratings<<"\n";
                for(int j=0; j<ratings; ++j)
                    flog<<rate[j]<<" ";
                flog<<"\n";
                flog<<fixed<<filme[k].getBudget()<<"\n";
                flog<<filme[k].getYear()<<"\n";
            }
            flog.close();
            cataloguser(u);
        }
        else
        {
            cataloguser(u);
        }
    }

}

void goodprem(premium u)
{
    system("cls");
    cout<<"Welcome "<<u.getUsername()<<"!";
    cout<<"\n";
    cout<<"1. Film Catalogue\n";
    cout<<"2. Settings\n";
    cout<<"3. Log Out\n";

    int x;
    cin>>x;
    switch(x)
    {
    case 1:
        cataloguser(u);
        break;
    case 2:
        premset(u);
        break;
    case 3:
        startmenu();
        break;
    default:
        goodprem(u);
        break;
    }
}

void goodadmin(admin u)
{
    system("cls");
    cout<<"Welcome "<<u.getUsername()<<"!";
    cout<<"\n";
    cout<<"1. Add film\n";
    cout<<"2. Add recommended\n";
    cout<<"3. Remove film\n";
    cout<<"4. Remove recommended\n";
    cout<<"5. Change default theme\n";
    cout<<"6. Log out\n";

    int x;
    cin>>x;
    switch(x)
    {
    case 1:
        addfilm(u);
        break;
    case 2:
        addad(u);
        break;
    case 3:
        delfilm(u);
        break;
    case 4:
        deladd(u);
        break;
    case 5:
        chthem(u);
        break;
    case 6:
        startmenu();
    }
}

void deladd(admin u)
{
    system("cls");
    cout<<"Add Recommended:\n";
    while(!vad.empty())
       vad.pop_back();
    char title[21];
    char director[21];
    char genre[21];
    int i;
    unsigned int ratings;
    float* rate;
    double budget;
    unsigned int year;
    int startdate[8];
    int stopdate[8];

    adlog.open("ads.txt", ios::in);
    adlog>>nrads;
    adlog.get();
    for(i=1; i<=nrads; ++i)
    {
        adlog.get(title, 20);
        cout<<i<<". "<<title<<"\n";
        adlog.get();
        adlog.get(director, 20);
        adlog.get();
        adlog.get(genre, 20);
        adlog.get();
        adlog>>ratings;
        adlog.get();
        rate = new float[ratings+1];
        for(int j=0;j<ratings; ++j)
        {
            float r;
            adlog>>r;
            rate[j]=r;
        }
        adlog.get();
        adlog>>budget;
        adlog.get();
        adlog>>year;
        adlog.get();
        for(int j=0; j<8; ++j)
            adlog>>startdate[j];
        adlog.get();
        for(int j=0; j<8; ++j)
            adlog>>stopdate[j];
        adlog.get();
        advertised f(title, director, genre, ratings, rate, budget, year, startdate, stopdate);
        vad.push_back(f);
    }
    adlog.close();

    cout<<"\nChoose the recommendation you want to remove: ";
    int x;
    cin>>x;
    vad.erase(vad.begin() + x-1);
    nrads--;

    adlog.open("ads.txt", ios::out | ios::trunc);
    adlog<<nrads<<"\n";
    for(int k=0; k<nrads; ++k)
    {
        adlog<<vad[k].getTitle()<<"\n";
        adlog<<vad[k].getDirector()<<"\n";
        adlog<<vad[k].getGenre()<<"\n";
        ratings=vad[k].getRate();
        rate=vad[k].getRatings();
        adlog<<ratings<<"\n";
        if(ratings!=0)
        {
            for(int j=0; j<ratings; ++j)
                adlog<<rate[j]<<" ";
            adlog<<"\n";
        }
        adlog<<fixed<<vad[k].getBudget()<<"\n";
        adlog<<vad[k].getYear()<<"\n";
        int* sta=vad[k].getStartdate();
        int* sto=vad[k].getStopdate();
        for(int j=0; j<8; ++j)
            adlog<<sta[j]<<" ";
        adlog<<"\n";
        for(int j=0; j<8; ++j)
            adlog<<sto[j]<<" ";
        adlog<<"\n";
    }
    adlog.close();

    cout<<"\nRecommended added\n";
    system("pause");
    goodadmin(u);
}

void delfilm(admin u)
{
    system("cls");
    cout<<"Remove film:\n";

    while(!filme.empty())
        filme.pop_back();

    char title[21];
    char director[21];
    char genre[21];
    int i;
    unsigned int ratings;
    float* rate;
    double budget;
    unsigned int year;
    int startdate[8];
    int stopdate[8];

    flog.open("films.txt", ios::in);
    flog>>nrfilme;
    flog.get();
    for(i=1; i<=nrfilme; ++i)
    {
        flog.get(title, 20);
        cout<<i<<". "<<title<<"\n";
        flog.get();
        flog.get(director, 20);
        flog.get();
        flog.get(genre, 20);
        flog.get();
        flog>>ratings;
        flog.get();
        rate = new float[ratings+1];
        for(int j=0;j<ratings; ++j)
        {
            float r;
            flog>>r;
            rate[j]=r;
        }
        flog.get();
        flog>>budget;
        flog.get();
        flog>>year;
        flog.get();
        film f(title, director, genre, ratings, rate, budget, year);
        filme.push_back(f);
    }
    flog.close();

    cout<<"\nChoose the film you want to remove: ";
    int x;
    cin>>x;
    filme.erase(filme.begin() + x-1);
    nrfilme--;

    flog.open("films.txt", ios::out | ios::trunc);
            flog<<nrfilme;
            flog<<"\n";
            for(int k=0; k<nrfilme; ++k)
            {
                flog<<filme[k].getTitle()<<"\n";
                flog<<filme[k].getDirector()<<"\n";
                flog<<filme[k].getGenre()<<"\n";
                ratings=filme[k].getRate();
                rate=filme[k].getRatings();
                flog<<ratings<<"\n";
                for(int j=0; j<ratings; ++j)
                    flog<<rate[j]<<" ";
                flog<<"\n";
                flog<<fixed<<filme[k].getBudget()<<"\n";
                flog<<filme[k].getYear()<<"\n";
            }
            flog.close();

    cout<<"\nMovie removed\n";
    system("pause");
    goodadmin(u);
}

void addad(admin u)
{
    system("cls");
    cout<<"Add Recommended:\n";
    while(!vad.empty())
       vad.pop_back();
    char title[21];
    char director[21];
    char genre[21];
    int i;
    unsigned int ratings;
    float* rate;
    double budget;
    unsigned int year;
    int startdate[8];
    int stopdate[8];

    adlog.open("ads.txt", ios::in);
    adlog>>nrads;
    adlog.get();
    for(i=1; i<=nrads; ++i)
    {
        adlog.get(title, 20);
        adlog.get();
        adlog.get(director, 20);
        adlog.get();
        adlog.get(genre, 20);
        adlog.get();
        adlog>>ratings;
        adlog.get();
        rate = new float[ratings+1];
        for(int j=0;j<ratings; ++j)
        {
            float r;
            adlog>>r;
            rate[j]=r;
        }
        adlog.get();
        adlog>>budget;
        adlog.get();
        adlog>>year;
        adlog.get();
        for(int j=0; j<8; ++j)
            adlog>>startdate[j];
        adlog.get();
        for(int j=0; j<8; ++j)
            adlog>>stopdate[j];
        adlog.get();
        advertised f(title, director, genre, ratings, rate, budget, year, startdate, stopdate);
        vad.push_back(f);
    }
    adlog.close();

    advertised f;
    cin>>f;
    vad.push_back(f);
    nrads++;

    adlog.open("ads.txt", ios::out | ios::trunc);
    adlog<<nrads<<"\n";
    for(int k=0; k<nrads; ++k)
    {
        adlog<<vad[k].getTitle()<<"\n";
        adlog<<vad[k].getDirector()<<"\n";
        adlog<<vad[k].getGenre()<<"\n";
        ratings=vad[k].getRate();
        rate=vad[k].getRatings();
        adlog<<ratings<<"\n";
        if(ratings!=0)
        {
            for(int j=0; j<ratings; ++j)
                adlog<<rate[j]<<" ";
            adlog<<"\n";
        }
        adlog<<fixed<<vad[k].getBudget()<<"\n";
        adlog<<vad[k].getYear()<<"\n";
        int* sta=vad[k].getStartdate();
        int* sto=vad[k].getStopdate();
        for(int j=0; j<8; ++j)
            adlog<<sta[j]<<" ";
        adlog<<"\n";
        for(int j=0; j<8; ++j)
            adlog<<sto[j]<<" ";
        adlog<<"\n";
    }
    adlog.close();

    cout<<"\nRecommended added\n";
    system("pause");
    goodadmin(u);
}

void addfilm(admin u)
{
    system("cls");
    cout<<"Add film:\n";

    while(!filme.empty())
       filme.pop_back();

    char title[21];
    char director[21];
    char genre[21];
    int i;
    unsigned int ratings;
    float* rate;
    double budget;
    unsigned int year;
    int startdate[8];
    int stopdate[8];

    flog.open("films.txt", ios::in);
    flog>>nrfilme;
    flog.get();
    for(i=1; i<=nrfilme; ++i)
    {
        flog.get(title, 20);
        flog.get();
        flog.get(director, 20);
        flog.get();
        flog.get(genre, 20);
        flog.get();
        flog>>ratings;
        flog.get();
        rate = new float[ratings+1];
        for(int j=0;j<ratings; ++j)
        {
            float r;
            flog>>r;
            rate[j]=r;
        }
        flog.get();
        flog>>budget;
        flog.get();
        flog>>year;
        flog.get();
        film f(title, director, genre, ratings, rate, budget, year);
        filme.push_back(f);
    }
    flog.close();

    film f;
    cin>>f;
    filme.push_back(f);
    nrfilme++;

    flog.open("films.txt", ios::out | ios::trunc);
            flog<<nrfilme;
            flog<<"\n";
            for(int k=0; k<nrfilme; ++k)
            {
                flog<<filme[k].getTitle()<<"\n";
                flog<<filme[k].getDirector()<<"\n";
                flog<<filme[k].getGenre()<<"\n";
                ratings=filme[k].getRate();
                rate=filme[k].getRatings();
                flog<<ratings<<"\n";
                for(int j=0; j<ratings; ++j)
                    flog<<rate[j]<<" ";
                flog<<"\n";
                flog<<fixed<<filme[k].getBudget()<<"\n";
                flog<<filme[k].getYear()<<"\n";
            }
            flog.close();

    cout<<"\nMovie added\n";
    system("pause");
    goodadmin(u);
}

void chthem(admin u)
{
    system("cls");
    cout<<"Choose theme\n";
    theme t;
    cin>>t;
    t.changeTheme();
    th.open("theme.txt", ios::out | ios::trunc);
    th<<t.getText()<<" "<<t.getBackground();
    th.close();
    system("pause");
    goodadmin(u);
}
