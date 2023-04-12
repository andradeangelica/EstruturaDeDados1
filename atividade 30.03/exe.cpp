#include <iostream>
using namespace std;

class Data
{
	private: 	
	   int dia;
	   int mes;
	   int ano;	
    public:
    	Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
    	void setDia(int dia)
    	{
			this->dia = dia;
		}
		void setMes(int mes)
    	{
			this->mes = mes;
		}
		void setAno(int ano)
    	{
			this->ano = ano;
		}
		int getDia()
		{
			return this->dia;
		}
		int getMes()
		{
			return this->mes;
		}
		int getAno()
		{
			return this->ano;
		}
		string getData()
		{
		    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
		}
		Data* dia_seguinte()
		{
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			Data *d1 = new Data(this->dia, this->mes, this->ano);
			
			if (d1->ano%4 == 0)
			{
				diasNoMes[1]++;
			}
			
			d1->dia++;
			if (d1->dia > diasNoMes[d1->mes-1])
			{
				d1->dia = 1;
				if (++d1->mes > 12)
				{
					d1->mes = 1;
					d1->ano++;
				}
			}
			
			return d1;
		}
};

class Contato
{
	
	private:
		string email;
		string nome;
		string telefone;		
		int idade;

	public:
		
		Contato(string Email, string Nome, string Telefone){
			
			email=Email;
			nome=Nome;
			telefone=Telefone;	
		}
		
		Contato(){
			this->email="kauelivio@gmail.com";
			this->nome="kaue";
			this->telefone="912349876";		
		}	
	
		void setIdade(int Idade){
			idade=Idade;
		}	  		
		
		string getIdade(){
			return to_string(idade);
		}
		
		void setEmail(string Email)
		{
			email=Email;
		}
		
		void setNome(string Nome)
		{
			nome=Nome;
		}
		
		void setTel(string Telefone)
		{
			telefone=Telefone;
		}
		
		string getEmail()
		{
			return email;
		}
		
		string getNome()
		{
			return nome;
		}
		
		string getTelefone()
		{
			return telefone;
		}
		
		void Idade(int dianasc,int mesnasc, int anonasc)
		{
			int diahj=17;
			int meshj=9;
			int anohj=2020;		
			
			if(mesnasc==meshj){
						
				if(dianasc<=diahj)
				{
					idade=anohj-anonasc;
				}
				else
				{idade=anohj-anonasc-1;}					
				
			}
			else if (mesnasc<=meshj) 
			{
				idade=anohj-anonasc;
			}
			else{idade=anohj-anonasc-1;}							
		}		
};


int main(int argc, char** argv)
{
	Contato *cont=new Contato();
	Data *data=new Data();
	string nome;
	string telefone;
	string email;
	int dia;
	int mes;
	int ano;
	
	cout<<"Nome: ";
	cin>>nome;
	cout<<endl;
	
	cout<<"Telefone: ";
	cin>>telefone;
	cout<<endl;

	cout<<"Email: ";
	cin>>email;
	cout<<endl;
	
	cout<<"Dia de nascimento: ";
	cin>>dia;
	cout<<endl;
	
	cout<<"Mes de nascimento: ";
	cin>>mes;
	cout<<endl;
	
	cout<<"Ano de nascimento: ";
	cin>>ano;
	cout<<endl;
	
	cont->setNome(nome);
	/cont->setEmail(email);
	cont->setTel(telefone);
	
	data->setDia(dia);
	data->setMes(mes);
	data->setAno(ano);
	
	cont->Idade(dia,mes,ano);
	
	cout<<cont->getNome()<< " - email: "<<cont->getEmail()<<" - tel: "<<cont->getTelefone()<<" - data de nascimento: "<<data->getData()<<endl;
	
	cout<<"Idade em relacao a data de 17/09/2020: "<<cont->getIdade() <<" anos";
	
	return 0;
}