#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Zona {
private:
	string denumire;
	bool* randuri;
	int nrRanduri;
	bool** scaune;
	int nrScaunePeRand;
	int pret;

public:
	Zona()
	{
		denumire = "Necunoscuta";
		randuri = nullptr;
		nrRanduri = 0;
		scaune = nullptr;
		nrScaunePeRand = 0;
		pret = 0;
	}

	Zona(string denumire, int nrRanduri, int nrScaunePeRand)
	{
		this->denumire = denumire;
		this->nrRanduri = nrRanduri;
		this->nrScaunePeRand = nrScaunePeRand;
		this->pret = pret;
	}

	~Zona()
	{
		if (nrRanduri > 0)
			delete[] randuri;
		for (int i = 0; i < nrRanduri; i++)
			if (scaune[i] != nullptr)
				delete[] scaune[i];
	}

	Zona(const Zona& z)
	{
		this->denumire = z.denumire;
		this->randuri = new bool[z.nrRanduri];
		for (int i = 0; i < z.nrRanduri; i++)
			this->randuri[i] = z.randuri[i];
		this->nrRanduri = z.nrRanduri;
		for (int i = 0; i < z.nrRanduri; i++)
			this->scaune[i] = new bool[z.nrScaunePeRand];
		for (int i = 0; i < z.nrRanduri; i++)
			for (int j = 0; j < z.nrScaunePeRand; j++)
				this->scaune[i][j] = z.scaune[i][j];
		this->nrScaunePeRand = z.nrScaunePeRand;
		this->pret = z.pret;
	}

	Zona operator=(Zona& z)
	{
		if (this != &z)
		{
			this->denumire = z.denumire;
			this->randuri = new bool[z.nrRanduri];
			for (int i = 0; i < z.nrRanduri; i++)
				this->randuri[i] = z.randuri[i];
			this->nrRanduri = z.nrRanduri;
			for (int i = 0; i < z.nrRanduri; i++)
				this->scaune[i] = new bool[z.nrScaunePeRand];
			for (int i = 0; i < z.nrRanduri; i++)
				for (int j = 0; j < z.nrScaunePeRand; j++)
					this->scaune[i][j] = z.scaune[i][j];
			this->nrScaunePeRand = z.nrScaunePeRand;
			this->pret = z.pret;
		}
		return *this;
	}

	string getDenumire()
	{
		return denumire;
	}

	void setDenumire(string denumireNoua)
	{
		if (denumireNoua != "")
			denumire = denumireNoua;
	}

	bool* getRanduri()
	{
		if (randuri != nullptr && nrRanduri > 0)
		{
			bool* copy = new bool[nrRanduri];
			for (int i = 0; i < nrRanduri; i++)
				copy[i] = randuri[i];
			return copy;
		}
	}

	void setRanduri(int* randuriNoi, int nr)
	{
		if (randuriNoi != nullptr && nr > 0)
		{
			if (randuri != nullptr)
				delete[] randuri;
			nrRanduri = nr;
			randuri = new bool[nr];
			for (int i = 0; i < nr; i++)
				randuri[i] = randuriNoi[i];
		}
	}

	int getNrRanduri()
	{
		return nrRanduri;
	}

	void setNrRanduri(int nr)
	{
		if (nr != 0)
			nrRanduri = nr;
	}

	bool** getScaune()
	{
		if (scaune != nullptr && nrRanduri > 0 && nrScaunePeRand > 0)
		{
			bool** copy;
			for (int i = 0; i < nrRanduri; i++)
				copy[i] = new bool[nrScaunePeRand];
			for (int i = 0; i < nrRanduri; i++)
				for (int j = 0; j < nrScaunePeRand; j++)
					copy[i][j] = scaune[i][j];
			return copy;
		}
	}

	void setScaune(int** scauneNoi, int nrNouRanduri, int nrNouScaunePeRand)
	{
		if (scauneNoi != nullptr && nrRanduri > 0 && nrScaunePeRand > 0)
		{
			if (scaune != nullptr)
				delete[] randuri;
			nrRanduri = nrNouRanduri;
			nrScaunePeRand = nrNouScaunePeRand;
			for (int i = 0; i < nrRanduri; i++)
				scaune[i] = new bool[nrScaunePeRand];
			for (int i = 0; i < nrRanduri; i++)
				for (int j = 0; j < nrScaunePeRand; j++)
					scaune[i][j] = scauneNoi[i][j];
		}
	}

	int getNrScaunePeRand()
	{
		return nrScaunePeRand;
	}

	void setNrScaunePeRand(int nr)
	{
		if (nr != 0)
			nrScaunePeRand = nr;
	}

	float getPret()
	{
		return pret;
	}

	void setPret(float pretNou)
	{
		if (pretNou > 0)
			pret = pretNou;
	}

	string lungimeRanduri(Zona e)
	{
		string lungime;
		if (e.nrScaunePeRand > 10)
			lungime = "Randurile au fiecare mai mult de 10 locuri";
		else lungime = "Randurile au cate maxim 10 locuri";
		return lungime;
	}

	bool randOcupat(Zona e, int i)
	{
		bool ocupat;
		if (e.randuri[i] = 1)
			ocupat = 1;
		else ocupat = 0;

	}

	Zona operator++()
	{
		nrRanduri++;
		return *this;
	}

	bool operator==(int nr)
	{
		if (nrScaunePeRand == nr)
			return 1;
		else return 0;
	}

	friend ostream& operator<<(ostream&, Zona);
	friend istream& operator>>(istream&, Zona&);
	friend class Locatie;
};

ostream& operator<<(ostream& out, Zona z)
{
	out << "Denumire: " << z.denumire << endl;
	out << "Nr. randuri: " << z.nrRanduri;
	for (int i = 0; i < z.nrRanduri; i++)
		if (z.randuri[i] = 1)
			out << "Randul " << i+1 << " este ocupat" << endl;
		else out << "Randul " << i+1 << " nu este ocupat" << endl;
	out << "Nr. scaune pe rand: " << z.nrScaunePeRand << endl;
	for (int i = 0; i < z.nrRanduri; i++)
		for (int j = 0; j < z.nrScaunePeRand; j++)
			if (z.scaune[i][j] = 1)
				out << "Scaunul " << j + 1 << " de pe randul " << i + 1 << " este ocupat" << endl;
			else out << "Scaunul " << j + 1 << " de pe randul " << i + 1 << " nu este ocupat" << endl;
	out << "Pret: " << z.pret << endl;

	return out;
}

istream& operator>>(istream& in, Zona& z)
{
	cout << "Denumire: "; in >> ws; getline(in, z.denumire);
	cout << "Nr. randuri: " << z.nrRanduri;
	cout << "Randuri: " << endl;
	if (z.randuri != nullptr)
	{
		delete[] z.randuri;
		z.randuri = nullptr;
	}
	z.randuri = new bool[z.nrRanduri];
	cout << "Introdu 1 daca randul este ocupat sau 0 daca randul nu este ocupat: " << endl;
	for (int i = 0; i < z.nrRanduri; i++)
	{
		cout << "Randul " << i+1 << ": ";
		in >> z.randuri[i];
	}
	cout << endl;
	cout << "Nr. scaune pe rand: "; in >> z.nrScaunePeRand;
	cout << "Introdu 1 daca scaunul este ocupat sau 0 daca scaunul nu este ocupat: " << endl;
	for(int i = 0; i < z.nrRanduri; i++)
		for (int j = 0; j < z.nrScaunePeRand; j++)
		{
			cout << "Scaunul " << j+1 << " de pe randul " << i+1 << ": ";
			in >> z.scaune[i][j];
			while (z.scaune[i][j] != 1 && z.scaune[i][j] != 0)
				in >> z.scaune[i][j];
		}
	cout << "Pret: "; in >> z.pret;

	return in;
}


class Locatie {
private:
	string denumire;
	Zona* zone;
	int nrMaxLocuri;
	int nrZone;
	string adresa;
	string localitate;
	static string tara;

public:
	Locatie()
	{
		denumire = "Necunoscuta";
		zone = nullptr;
		nrZone = 0;
		nrMaxLocuri = 0;
		adresa = "Necunoscuta";
		localitate = "Necunoscuta";
	}

	Locatie(string denumire, Zona* zone, int nrZone, int nrMaxLocuri, int* randuri, int nrRanduri, int** scaune, int nrScaunePeRand, string adresa, string localitate)
	{
		this->denumire = denumire;
		this->zone = new Zona[nrZone];
		for (int i = 0; i < nrZone; i++)
			this->zone[i] = zone[i];
		this->nrZone = nrZone;
		this->nrMaxLocuri = nrMaxLocuri;
		this->adresa = adresa;
		this->localitate = localitate;
	}

	~Locatie()
	{
		if (nrZone > 0)
			delete[] zone;
	}

	Locatie(const Locatie& l)
	{
		this->denumire = l.denumire;
		this->zone = new Zona[l.nrZone];
		for (int i = 0; i < l.nrZone; i++)
			this->zone[i] = l.zone[i];
		this->nrZone = l.nrZone;
		this->nrMaxLocuri = l.nrMaxLocuri;
		this->adresa = l.adresa;
		this->localitate = l.localitate;
	}

	Locatie operator=(Locatie& l)
	{
		if (this != &l)
		{
			this->denumire = l.denumire;
			this->zone = new Zona[l.nrZone];
			for (int i = 0; i < l.nrZone; i++)
				this->zone[i] = l.zone[i];
			this->nrZone = l.nrZone;
			this->nrMaxLocuri = l.nrMaxLocuri;
			this->adresa = l.adresa;
			this->localitate = l.localitate;
		}
		return *this;
	}

	string getDenumire()
	{
		return denumire;
	}

	void setDenumire(string denumireNoua)
	{
		if (denumireNoua != "")
			denumire = denumireNoua;
	}

	Zona* getZone()
	{
		if (zone != nullptr && nrZone > 0)
		{
			Zona* copy = new Zona[nrZone];
			for (int i = 0; i < nrZone; i++)
				copy[i] = zone[i];
			return copy;
		}
	}

	void setZone(Zona* zoneNoi, int nr)
	{
		if (zoneNoi != nullptr && nr > 0)
		{
			if (zone != nullptr)
				delete[] zone;
			nrZone = nr;
			zone = new Zona[nr];
			for (int i = 0; i < nr; i++)
				zone[i] = zoneNoi[i];
		}
	}

	int getNrZone()
	{
		return nrZone;
	}

	void setNrZone(int nrZoneNoi)
	{
		if (nrZoneNoi != 0)
			nrZone = nrZoneNoi;
	}

	int getNrMaxLocuri()
	{
		return nrMaxLocuri;
	}

	void setNrMaxLocuri(int nr)
	{
		if (nr != 0)
			nrMaxLocuri = nr;
	}

	string getAdresa()
	{
		return adresa;
	}

	void setAdresa(string adresaNoua)
	{
		if (adresaNoua != "")
			adresa = adresaNoua;
	}

	string getLocalitate()
	{
		return localitate;
	}

	void setLocalitate(string localitateNoua)
	{
		if (localitateNoua != "")
			adresa = localitateNoua;
	}

	static string getTara()
	{
		return tara;
	}

	static void setTara(string taraNoua)
	{
		if (taraNoua != "")
			Locatie::tara = taraNoua;
	}

	string marimeLocatie(Locatie l)
	{
		string marime;
		if (l.nrMaxLocuri > 5000)
			marime = "Locatie foarte incapatoare";
		else marime = "Locatie acceptabila si pentru evenimente mai mici";
		return marime;
	}

	string zoneleLocatiei(Locatie l)
	{
		string dotari;
		if (l.nrZone <= 2)
			dotari = "Locatia are maxim 2 zone unde spectatorii pot sta";
		else dotari = "Locatia are minim 3 zone unde spectatorii pot sta";
		return dotari;
	}

	bool operator!()
	{
		return localitate != "Bucuresti";
	}

	operator int()
	{
		return nrMaxLocuri;
	}

	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);
	friend class Eveniment;
};
string Locatie::tara = "Romania";

ostream& operator<<(ostream& out, Locatie l)
{
	out << "Denumire: " << l.denumire << endl;
	out << "Nr. maxim de locuri: " << l.nrMaxLocuri << endl;
	out << "Adresa " << l.adresa << endl;
	out << "Localitate: " << l.localitate << endl;
	out << "Tara: " << l.getTara << endl;
	out << "Nr. zone: " << l.nrZone << endl;
	out << "Zone: ";
	for (int i = 0; i < l.nrZone; i++)
	{
		out << "Detalii despre zona " << i << ": ";
		ostream& operator<<(ostream& out, Zona z);
	}


	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	cout << "Denumire: "; in >> ws; getline(in, l.denumire);
	cout << "Nr. maxim de locuri: "; in >> l.nrMaxLocuri;
	cout << "Adresa: "; in >> ws; getline(in, l.adresa);
	cout << "Localitate: "; in >> ws; getline(in, l.localitate);
	cout << "Tara: "; in >> ws; getline(in, l.tara);
	cout << "Nr. zone: ";  in >> l.nrZone;
	cout << "zone: ";
	if (l.zone != nullptr)
	{
		delete[] l.zone;
		l.zone = nullptr;
	}
	l.zone = new Zona[l.nrZone];
	for (int i = 0; i < l.nrZone; i++)
	{
		cout << "Zona " << i << ": " << endl;
		in >> l.zone[i];
	}

	return in;
}



class Eveniment {
private:
	string denumire;
	char* domeniuEveniment;
	string data;
	int ora;
	Locatie locatieEveniment;

public:
	Eveniment()
	{
		denumire = "Necunoscuta";
		domeniuEveniment = nullptr;
		data = "Necunoscuta";
		ora = 0;
	}

	Eveniment(string denumire, char* domeniuEveniment, string data, int ora)
	{
		this->denumire = denumire;
		this->domeniuEveniment = domeniuEveniment;
		this->data = data;
		this->ora = ora;
	}

	~Eveniment()
	{
		if (domeniuEveniment != nullptr)
			delete[] domeniuEveniment;
	}

	Eveniment(Eveniment& e)
	{
		this->denumire = e.denumire;
		this->domeniuEveniment = e.domeniuEveniment;
		this->data = e.data;
		this->ora = e.ora;
		this->locatieEveniment = e.locatieEveniment;
	}

	Eveniment operator=(Eveniment& e)
	{
		if (this != &e)
		{
			this->denumire = e.denumire;
			this->domeniuEveniment = e.domeniuEveniment;
			this->data = e.data;
			this->ora = e.ora;
			this->locatieEveniment = e.locatieEveniment;
		}
		return *this;
	}

	string getDenumire()
	{
		return denumire;
	}

	void setDenumire(string denumireNoua)
	{
		if (denumireNoua != "")
			denumire = denumireNoua;
	}

	char* getDomeniuEveniment()
	{
		int n = strlen(domeniuEveniment);
		if (n > 0)
		{
			char* copy = new char[n + 1];
			strcpy_s(copy, n + 1, domeniuEveniment);
			return copy;
		}
		return NULL;
	}

	void setdomeniuEveniment(const char* domeniuNou)
	{
		int n = strlen(domeniuNou);
		if (n > 0)
		{
			delete[] domeniuEveniment;
			denumire = new char[n + 1];
			strcpy_s(domeniuEveniment, n + 1, domeniuNou);
		}
	}

	string getdata()
	{
		return data;
	}

	void setData(string dataNoua)
	{
		if (dataNoua != "")
			data = dataNoua;
	}

	int getOra()
	{
		return ora;
	}

	void setOra(int oraNoua)
	{
		if (oraNoua > 0 && oraNoua < 24)
			ora = oraNoua;
	}

	Locatie getLocatieEveniment()
	{
		return locatieEveniment;
	}

	void setLocatieEveniment(Locatie l)
	{
		if (l.denumire != "")
			locatieEveniment = l;

	}

	string programariEvenimente()
	{
		string perioada;
		if (ora >= 18)
			perioada = "Seara";
		else perioada = "In timpul zilei";
	}

	int evenimenteCeIncepInainteDe20(Eveniment* e, int nr)
	{
		int contor = 0;
		if (ora < 20)
			contor++;
		return contor;
	}

	char& operator[](int index)
	{
		if (index >= 0 && domeniuEveniment != nullptr && index < strlen(domeniuEveniment))
			return domeniuEveniment[index];
	}

	bool operator<(int oraFixa)
	{
		if (ora < oraFixa)
			return 1;
		else return 0;
	}

	virtual string accesServicii(int donatie)
	{
		string serviciu;
		if (donatie > 50)
			serviciu = "Degustare vin";
		return serviciu;
	}

	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
	friend ifstream& operator>>(ifstream&, Eveniment&);
	friend class Bilet;
};

ostream& operator<< (ostream& out, Eveniment e)
{
	out << "Denumire: " << e.denumire << endl;
	out << "Domeniul din care face parte evenimentul: " << e.domeniuEveniment << endl;
	out << "Data: " << e.data << endl;
	out << "Ora: " << e.ora << endl;
	out << "Detalii despre locatie: ";
	ostream& operator<< (ostream & out, Locatie l);
	return out;
}

istream& operator>> (istream& in, Eveniment& e)
{
	cout << "Denumire: "; in >> ws; getline(in, e.denumire);
	if (e.domeniuEveniment != nullptr)
	{
		delete[] e.domeniuEveniment;
		e.domeniuEveniment = nullptr;
	}
	e.domeniuEveniment = new char[100];
	cout << "Domeniul din care face parte evenimentul: "; in >> e.domeniuEveniment;
	cout << "Data: "; in >> e.data;
	cout << "Ora: "; in >> e.ora; cout << endl;
	cout << "Detalii despre locatie: " << endl;
	in >> e.locatieEveniment;
	return in;
}


class Bilet {
private:
	const int id;
	int pret;

public:
	Bilet() : id(id)
	{
		pret = 0;
	}

	Bilet(int id, float pret) : id(id)
	{
		this->pret = pret;
	}

	static float pretMediu(Bilet* b, int nrBilete)
	{
		float s = 0;
		for (int i = 0; i < nrBilete; i++)
			s = s + b[i].pret;
		return s / nrBilete;
	}

	const int getId()
	{
		return id;
	}

	float getPret()
	{
		return pret;
	}

	void setPret(float pretNou)
	{
		if (pretNou > 0)
			pret = pretNou;
	}

	int nrBileteScumpe(Bilet* b, int nr)
	{
		int contor = 0;
		for (int i = 0; i < nr; i++)
			if (b[i].pret > 200)
				contor++;
		return contor;
	}

	int biletRedus(float discount)
	{
		pret = pret - discount * pret;
		return pret;
	}

	Bilet operator+(Bilet b)
	{
		Bilet copy = *this;
		copy.pret = copy.pret + b.pret;
		return copy;
	}

	Bilet operator-(float valoare)
	{
		Bilet copy = *this;
		copy.pret = copy.pret - valoare;
		return copy;
	}

	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
	friend class Tombola;
};

ostream& operator<<(ostream& out, Bilet b)
{
	out << "ID: " << b.id << endl;
	out << "Pret: " << b.pret << endl;
	return out;
}

istream& operator>>(istream& in, Bilet& b)
{
	cout << "Pret: "; in >> b.pret;
	return in;
}

class ActivitateExtra : public Eveniment
{

public:
	string accesServicii(int donatie)
	{
		string serviciu;
		if (donatie < 100)
			serviciu = "Acces doar la bauturi";
		else serviciu = "Acces atat la bauturi, cat si la mancare";
		return serviciu;
	}
};

class Tombola
{
private:
	Bilet b;

public:
	virtual string premiiPosibile(unsigned taxa) = 0;
	virtual bool sansaMaiMare(unsigned taxaNoua)
	{
		if (taxaNoua > 150)
			return 1;
		else return 0;
	}

};

class Castig : public Tombola
{
public:
	string premiiPosibile(unsigned taxa)
	{
		string premii;
		if (taxa < 40)
			premii = "plusuri";
		else if (taxa < 75)
			premii = "plusuri, carti";
		else premii = "plusuri, carti, casti audio";
		return premii;
	}

	bool sansaMaiMare(unsigned taxa_Noua)
	{
		if (taxa_Noua < 100)
			return 0;
		else return 1;
	}
};

int main()
{
	
}
