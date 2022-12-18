#include <iostream>
#include <string>
using namespace std;

class Locatie {
private:
	string denumire;
	string* zone;
	int nrZone;
	int nrMaxLocuri;
	bool* randuri;
	int nrRanduri;
	bool** scaune;
	int nrScaunePeRand;
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
		randuri = nullptr;
		nrRanduri = 0;
		scaune = nullptr;
		nrScaunePeRand = 0;
		adresa = "Necunoscuta";
		localitate = "Necunoscuta";
	}

	Locatie(string denumire, string* zone, int nrZone, int nrMaxLocuri, int* randuri, int nrRanduri, int** scaune, int nrScaunePeRand, string adresa, string localitate)
	{
		this->denumire = denumire;
		this->zone = new string[nrZone];
		for (int i = 0; i < nrZone; i++)
			this->zone[i] = zone[i];
		this->nrZone = nrZone;
		this->nrMaxLocuri = nrMaxLocuri;
		this->randuri = new bool[nrRanduri];
		for (int i = 0; i < nrRanduri; i++)
			this->randuri[i] = randuri[i];
		this->nrRanduri = nrRanduri;
		for (int i = 0; i < nrRanduri; i++)
			this->scaune[i] = new bool[nrScaunePeRand];
		for (int i = 0; i < nrRanduri; i++)
			for (int j = 0; j < nrScaunePeRand; j++)
				this->scaune[i][j] = scaune[i][j];
		this->nrScaunePeRand = nrScaunePeRand;
		this->adresa = adresa;
		this->localitate = localitate;
	}

	~Locatie()
	{
		if (nrZone > 0)
			delete[] zone;
		if (nrRanduri > 0)
			delete[] randuri;
		if (scaune != nullptr)
			delete[] scaune;
	}

	Locatie(const Locatie& l)
	{
		this->denumire = l.denumire;
		this->zone = new string[l.nrZone];
		for (int i = 0; i < l.nrZone; i++)
			this->zone[i] = l.zone[i];
		this->nrZone = l.nrZone;
		this->nrMaxLocuri = l.nrMaxLocuri;
		this->randuri = new bool[l.nrRanduri];
		for (int i = 0; i < l.nrRanduri; i++)
			this->randuri[i] = l.randuri[i];
		this->nrRanduri = l.nrRanduri;
		for (int i = 0; i < l.nrRanduri; i++)
			this->scaune[i] = new bool[l.nrScaunePeRand];
		for (int i = 0; i < l.nrRanduri; i++)
			for (int j = 0; j < l.nrScaunePeRand; j++)
				this->scaune[i][j] = l.scaune[i][j];
		this->nrScaunePeRand = l.nrScaunePeRand;
		this->adresa = l.adresa;
		this->localitate = l.localitate;
	}

	Locatie operator=(Locatie& l)
	{
		if (this != &l)
		{
			this->denumire = l.denumire;
			this->zone = new string[l.nrZone];
			for (int i = 0; i < l.nrZone; i++)
				this->zone[i] = l.zone[i];
			this->nrZone = l.nrZone;
			this->nrMaxLocuri = l.nrMaxLocuri;
			this->randuri = new bool[l.nrRanduri];
			for (int i = 0; i < l.nrRanduri; i++)
				this->randuri[i] = l.randuri[i];
			this->nrRanduri = l.nrRanduri;
			for (int i = 0; i < l.nrRanduri; i++)
				this->scaune[i] = new bool[l.nrScaunePeRand];
			for (int i = 0; i < l.nrRanduri; i++)
				for (int j = 0; j < l.nrScaunePeRand; j++)
					this->scaune[i][j] = l.scaune[i][j];
			this->nrScaunePeRand = l.nrScaunePeRand;
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

	string* getZone()
	{
		if (zone != nullptr && nrZone > 0)
		{
			string* copy = new string[nrZone];
			for (int i = 0; i < nrZone; i++)
				copy[i] = zone[i];
			return copy;
		}
	}

	void setZone(string* zoneNoi, int nr)
	{
		if (zoneNoi != nullptr && nr > 0)
		{
			if (zone != nullptr)
				delete[] zone;
			nrZone = nr;
			zone = new string[nr];
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
};
string Locatie::tara = "Romania";

ostream& operator<<(ostream& out, Locatie l)
{
	out << "Denumire: " << l.denumire << endl;
	out << "Nr. zone: " << l.nrZone << endl;
	out << "zone: ";
	for (int i = 0; i < l.nrZone; i++)
		out << l.zone[i] << " ";
	out << endl;
	out << "Nr. maxim de locuri: " << l.nrMaxLocuri << endl;
	out << "Nr. randuri: " << l.nrRanduri;
	for (int i = 0; i < l.nrRanduri; i++)
		out << l.randuri[i] << " ";
	out << endl;
	out << "Nr. scaune pe rand: " << l.nrScaunePeRand << endl;
	out << "Adresa " << l.adresa << endl;
	out << "Localitate: " << l.localitate << endl;
	out << "Tara: " << l.getTara << endl;

	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	cout << "Denumire: "; in >> l.denumire;
	cout << "Nr. zone: ";  in >> l.nrZone;
	cout << "zone: ";
	if (l.zone != nullptr)
	{
		delete[] l.zone;
		l.zone = nullptr;
	}
	l.zone = new string[l.nrZone];
	for (int i = 0; i < l.nrZone; i++)
		in >> l.zone[i];
	cout << endl;
	cout << "Nr. maxim de locuri: "; in >> l.nrMaxLocuri;
	cout << "Randuri: ";
	cout << "Nr. randuri: " << l.nrRanduri;
	if (l.randuri != nullptr)
	{
		delete[] l.randuri;
		l.randuri = nullptr;
	}
	l.randuri = new bool[l.nrRanduri];
	for (int i = 0; i < l.nrRanduri; i++)
		in >> l.randuri[i];
	cout << endl;
	cout << "Nr. scaune pe rand: "; in >> l.nrScaunePeRand;
	cout << "Adresa: "; in >> l.adresa;
	cout << "Localitate: "; in >> l.localitate;
	cout << "Tara: "; in >> l.tara;

	return in;
}


class Eveniment {
private:
	char* denumire;
	string data;
	int ora;

public:
	Eveniment()
	{
		denumire = nullptr;
		data = "Necunoscuta";
		ora = 0;
	}

	Eveniment(char* denumire, string data, int ora)
	{
		this->denumire = denumire;
		this->data = data;
		this->ora = ora;
	}

	~Eveniment()
	{
		if (denumire != nullptr)
			delete[] denumire;
	}

	Eveniment(const Eveniment& e)
	{
		this->denumire = e.denumire;
		this->data = e.data;
		this->ora = e.ora;
	}

	Eveniment operator=(Eveniment& e)
	{
		if (this != &e)
		{
			this->denumire = e.denumire;
			this->data = e.data;
			this->ora = e.ora;
		}
		return *this;
	}

	char* getDenumire()
	{
		int n = strlen(denumire);
		if (n > 0)
		{
			char* copy = new char[n + 1];
			strcpy_s(copy, n + 1, denumire);
			return copy;
		}
		return NULL;
	}

	void setDenumire(const char* denumireNoua)
	{
		int n = strlen(denumireNoua);
		if (n > 0)
		{
			delete[] denumire;
			denumire = new char[n + 1];
			strcpy_s(denumire, n + 1, denumireNoua);
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
		if (index >= 0 && denumire != nullptr && index < strlen(denumire))
			return denumire[index];
	}

	bool operator<(int oraFixa)
	{
		if (ora < oraFixa)
			return 1;
		else return 0;
	}

	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
};

ostream& operator<< (ostream& out, Eveniment e)
{
	out << "Denumire: " << e.denumire << endl;
	out << "Data: " << e.data << endl;
	out << "Ora: " << e.ora << endl;
	return out;
}

istream& operator>> (istream& in, Eveniment& e)
{
	if (e.denumire != nullptr)
	{
		delete[] e.denumire;
		e.denumire = nullptr;
	}
	e.denumire = new char[100];
	cout << "Denumire: "; in >> e.denumire;
	cout << "Data: "; in >> e.data;
	cout << "Ora: "; in >> e.ora;
	return in;
}


class Bilet {
private:
	const int id;
	float pret;

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

int main()
{

}