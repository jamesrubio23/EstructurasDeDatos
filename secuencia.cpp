#include<iostream>
using namespace std;

const string FLECHA = "↓";

struct nodo_secuencia{
  int elem;
  nodo_secuencia * sig =NULL ;
};

//typedef nodo_secuencia *secuencia;

struct secuencia{
  nodo_secuencia * primero;
  nodo_secuencia * anterior ;
};

secuencia crear(){
  secuencia s;
  nodo_secuencia * aux = new nodo_secuencia;
  s.primero = aux;
  s.anterior = s.primero;
  return s;
}

void insertar(secuencia & s, int e){
  nodo_secuencia * aux = new nodo_secuencia;
  aux->elem = e;
  aux->sig = s.anterior->sig;
  s.anterior->sig = aux;
  s.anterior = aux;
}

void eliminar(secuencia & s){
  nodo_secuencia * aux = s.anterior->sig;
  if(!(s.anterior->sig ==NULL)){
    s.anterior->sig = aux->sig;
    delete aux;
  
  }
}

void avanzar(secuencia & s){
  if(s.anterior->sig != NULL){
    s.anterior = s.anterior->sig;
  }
}

void actual(secuencia  & s){
  if(!(s.anterior->sig ==NULL)){
    cout<<s.anterior->sig->elem<<endl;
  }
  else{
    throw runtime_error(" final de la  secuencia");
  }
};

bool is_secuencia_vacia(secuencia & s){
  return (s.primero->sig ==NULL);
};

void mostrar(int e){
  cout<<e<<" ";
};

void mostrar(secuencia & s){
    nodo_secuencia * aux = s.primero;
    while(aux->sig != NULL){
      if(aux == s.anterior){
        cout << FLECHA;
      }
      mostrar(aux->sig->elem);
      aux = aux->sig;
    }
    cout<<" "<<endl;
};

void reiniciar(secuencia & s){
  s.anterior = s.primero;
}

bool fin(secuencia s){
  return s.anterior->sig == NULL;
}

void liberar(secuencia & s){
  reiniciar(s);
  while(!fin(s)){
    eliminar(s);
  }
  delete s.primero;
}

int main(){
  secuencia s;
  
  s = crear();
  for(int i=0;i<10;i++){
    insertar(s,i);
  }
  
  cout<<"Añadimos del 0 al 9 en la secuencia"<<endl;
  
  cout<<"primero es el ";
  cout<<s.primero->elem<<endl;
  
  cout<<"anterior es el ";
  cout<<s.anterior->elem<<endl;

  mostrar(s);
  
  cout<<endl;
  
  cout<<"Reiniciamos"<<endl;
  reiniciar(s);
  
  cout<<"primero es el ";
  cout<<s.primero->elem<<endl;
  
  cout<<"anterior es el ";
  cout<<s.anterior->elem<<endl;

  mostrar(s);
  
  cout<<endl;
  
  cout<<"Eliminamos uno"<<endl;
  eliminar(s);
  mostrar(s);
  
  cout<<endl;
  
  cout<<"Insertamos el 100 y 200"<<endl;
  insertar(s,100);
  insertar(s,200);
  cout<<"primero es el ";
  cout<<s.primero->elem<<endl;
  
  cout<<"anterior es el ";
  cout<<s.anterior->elem<<endl;
  
  mostrar(s);
  
  cout<<endl;
  
  cout<<"Avanzamos"<<endl;
  avanzar(s);
  cout<<"primero es el ";
  cout<<s.primero->elem<<endl;
  
  cout<<"anterior es el ";
  cout<<s.anterior->elem<<endl;
  
  mostrar(s);
  
  cout<<"El actual es "<<endl;
  actual(s);
  
  cout<<endl;
  
  cout<<"Eliminamos"<<endl;
  eliminar(s);
  
  cout<<"El actual es "<<endl;
  actual(s);
  
  cout<<"primero es el ";
  cout<<s.primero->elem<<endl;
  
  cout<<"anterior es el ";
  cout<<s.anterior->elem<<endl;
  mostrar(s);
  
  cout<<endl;
  
 
  cout<<"El actual es"<<endl;
  actual(s);
  cout<<endl;
  
  cout<<"s.primero->sig es"<<endl;
  cout<<s.primero->sig<<endl;
  
  
  cout<<endl;
  
  cout<<"Reiniciamos"<<endl;
  reiniciar(s);
  mostrar(s);
  
  
  
};


