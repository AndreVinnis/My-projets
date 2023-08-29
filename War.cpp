#include <iostream>
#include <cstdlib>
#include <time.h> 
using namespace std;

void sorteio(int da[],int ata, int de[], int def);
void contar(int da[], int de[], int cont[]);
void organizar(int da[], int de[], int cont[]);
void comparar(int da[], int de[], int cont[], int tropas_per[]);
void exibir(int da[], int de[], int cont[], int tropas_per[]);

int main(){
  int ataque, defesa;
  int ataquein, defesain;
  int dados_a[3],dados_d[3];
  int contar_dados[2];
  int tropas_perdidas[2];
  string parada;
  srand(time(NULL));

  cout << "Quantas tropas estao atacando: \n";
  cin >> ataquein;
  ataque = ataquein - 1;
  cout << "Quantas tropas estao defendendo: \n";
  cin >> defesain;
  defesa = defesain;

  while (ataque && defesa > 0){
    sorteio(dados_a, ataque, dados_d, defesa);
    contar(dados_a, dados_d, contar_dados);
    organizar(dados_a, dados_d, contar_dados);
    comparar(dados_a, dados_d, contar_dados, tropas_perdidas);
    exibir(dados_a, dados_d, contar_dados, tropas_perdidas);
    ataque -= tropas_perdidas[0];
    defesa -= tropas_perdidas[1];
    cin >> parada;
  }

  if (ataque > defesa){
    cout << "-----Vitoria do ataque-----" << endl;
    cout << "Tropas iniciais: " << ataquein << endl;
    cout << "Tropas perdidas: " << ataquein - (ataque + 1)  << endl;
  }
  else{
    cout << "-----Vitoria da defesa-----" << endl;
    cout << "Tropas iniciais: " << defesain << endl;
    cout << "Tropas perdidas: " << defesain - defesa << endl;
  }
} 

/*Sorteio dos dados;*/
void sorteio(int da[], int ata, int de[], int def){
  for (int i = 0; i < 3; i++){
    da[i] = 0;
    de[i] = 0;
  }

// ataque de 3:
 if (ata >=3){
   for ( int i=0; i < 3; i++){
      
      int a = rand() % 7;
      if (a ==0){a=1;}
      da[i] = a;
    }
// ataque de 2:
  } else if (ata >= 2){
   for ( int i=0; i < 2; i++){
      
      int a = rand() % 7;
      if (a ==0){a=1;}
      da[i] = a;
    }
// ataque de 1:
  } else {
   for ( int i=0; i < 1; i++){
      
      int a = rand() % 7;
      if (a ==0){a=1;}
      da[i] = a;
    }
  }

// defesa de 3:
 if (def >=3){
   for ( int i=0; i < 3; i++){
      int a = rand() % 7;
      if (a ==0){a=1;}
      de[i] = a;
    }
// defesa de 2:
  } else if (def >= 2){
   for ( int i=0; i < 2; i++){  
      int a = rand() % 7;
      if (a ==0){a=1;}
      de[i] = a;
    }
// defesa de 1:
  } else {
   for ( int i=0; i < 1; i++){    
      int a = rand() % 7;
      if (a ==0){a=1;}
      de[i] = a;
    }
  }
}

/*Contar os dados;*/
void contar(int da[], int de[], int cont[]){
  int num_da = 0;
  int num_de = 0;
  for (int i = 0; i < 3; i ++){
    if (da[i] != 0){
      num_da += 1;
    }
  }

  for (int i = 0; i < 3; i ++){
    if (de[i] != 0){
      num_de += 1;
    }
  }

  cont[0] = num_da;
  cont[1] = num_de;
}

/*Organizar dados;*/
void organizar(int da[], int de[], int cont[]){
  int variavel;
  int i;
  int maiorA = da[0];
  int menorA = da[0];
  int maiorD = de[0];
  int menorD = de[0];

// ataque:
  if (cont[0] == 3){i=2;}
  else if(cont[0] == 2){i=1;}
  for (int c = 0; c < cont[0]; c++){
    if (da[c] < menorA){menorA = da[c];}
    if (da[c] > maiorA){maiorA = da[c];}
    }
  
  
  while (menorA != da[cont[0]-1] ||  maiorA != da[0]){
    variavel = 0;
      if (da[i] > da[i-1]){
        variavel = da[i];
        da[i] = da[i-1];
        da[i-1] = variavel;
        i -= 1;
      } else{i -= 1;}

      if (i == 0){i=2;}
  }
  
  
// defesa:
  if (cont[1] == 3){i=2;}
  else if(cont[1] == 2){i=1;}
  for (int c = 0; c < cont[1]; c++){
    if (de[c] < menorD){menorD = de[c];}
    if (de[c] > maiorD){maiorD = de[c];}
  }
  
  while (menorD != de[cont[1]-1] ||  maiorD != de[0]){
    variavel = 0;
      if (de[i] > de[i-1]){
        variavel = de[i];
        de[i] = de[i-1];
        de[i-1] = variavel;
        i -= 1;
      } else{i -= 1;}

      if (i == 0){i=2;}
    }  
} 

/*Comparação dos dados;*/
void comparar(int da[], int de[], int cont[], int tropas_per[]){
  int quant;
  int tp_ata = 0;
  int tp_def = 0;

  if (cont[0] > cont[1]){quant = cont[1];}
  else if(cont[1] < cont[0]){quant = cont[0];}
  else{quant = cont[0];}

  for ( int i = 0; i < quant; i ++){
    if (da[i] > de[i]){tp_def += 1;}
    else{tp_ata += 1;}

  tropas_per[0] = tp_ata;
  tropas_per[1] = tp_def;
  }
}

/*Exibir resultados;*/
void exibir(int da[], int de[], int cont[], int tropas_per[]){
  cout << "---------------Ataque---------------" << endl;
  cout << "Dados: "; 
  for ( int i = 0; i < cont[0]; i ++){
    cout << da[i];
  }
  cout << endl;

  cout << "---------------Defesa---------------" << endl;
  cout << "Dados: "; 
  for ( int i = 0; i < cont[1]; i ++){
    cout << de[i];
  }
  cout << endl;
  cout << "------------------------------------" << endl;
  cout << endl;

  cout << "Baixas ataque: " << tropas_per[0] << endl;
  cout << "Baixas defesa: " << tropas_per[1] << endl;
}
