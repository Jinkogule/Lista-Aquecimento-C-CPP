#pragma once // evita múltiplas definições

#include <iostream>
#include <tuple>

using namespace std;

// exemplo útil:
int exemplo(const char *cstr)
{
   int n, count;
   sscanf(cstr, "%d%n", &n, &count);
   cstr += count;
   int s = 0;
   while (n--)
   {
      int v = 0;
      sscanf(cstr, "%d%n", &v, &count);
      cstr += count;
      s += v;
   }
   return s;
}

//exercício 0
int exercicio0(const char* cstr){
    return 0;
}

//exercício 1
int exercicio1(const char* cstr){

    int a, b, soma, count;

    sscanf(cstr, "%d %d%n", &a, &b, &count); cstr += count;

    if (b>a){
        soma=a;
        for (int i=a+1; i<=b; i++){
            soma+=i;
        }
    }
    else if (a>b){
        soma=b;
        for (int i=b+1; i<=a; i++){
            soma+=i;
        }
    }
    return soma;
}


//exercicio 2
int exercicio2(const char* cstr){

    int N, aux, count, cand1=0, cand2=0, cand3=0, nulo=0;
    
    sscanf(cstr, "%d%n", &N, &count); cstr += count;

    for (int i=0; i<N; i++){
        sscanf(cstr, "%d%n", &aux, &count); cstr += count;
        if (aux==0){
            nulo+=1;
        }
        else if (aux==1){
            cand1+=1;
        }
        else if (aux==2){
            cand2+=1;
        }
        else if (aux==3){
            cand3+=1;
        }
    }
    if ((cand1>cand2)&&(cand1>cand3)&&(cand1>nulo)){
        return 1;
    }
    else if ((cand2>cand1)&&(cand2>cand3)&&(cand2>nulo)){
        return 2;
    }
    else if ((cand3>cand1)&&(cand3>cand2)&&(cand3>nulo)){
        return 3;
    }
    else{
        return 0;
    }
}

//exercicio 3
tuple <float, float, float, float> exercicio3(const char* cstr){

    int N, count;
    sscanf(cstr, "%d%n", &N, &count); cstr += count;

    float num, lista[N], soma = 0, media = 0, max = 0, min = 0;

    for (int i=0; i<N; i++){
        sscanf(cstr, "%f%n", &num, &count); cstr += count;
        lista[i]=num;
        soma+=num;
    }
    media=(soma/N);
    
    max=lista[0];
    for (int i=0; i<N; i++){
        if (lista[i]>max){
            max=lista[i];
        }
    }
    
    min=lista[0];
    for (int i=0; i<N; i++){
        if (lista[i]<min){
            min=lista[i];
        }
    }

    return make_tuple(soma, media, max, min);
}
//exercicio 4
int exercicio4(const char* cstr){
    
    int N, k, count;
    sscanf(cstr, "%d%n", &N, &count); cstr += count;

    char nomes[N][10];
    float notas[N];
    
    for (int i=0; i<N; i++){
        sscanf(cstr, "%f %s%n", &notas[i], nomes[i], &count); cstr += count;
    }

    sscanf(cstr, "%d%n", &k, &count); cstr += count;
    printf("//Aluno %d//\nNome: %s\nNota: %.1f\n", k, nomes[k-1], notas[k-1]);

    if (notas[k-1]>=6){
        return 1;
    }
    else{
        return 0;
    }
} 

//exercicio 5
int exercicio5(const char* cstr){

    int N, count;
    
    sscanf(cstr, "%d%n", &N, &count); cstr += count;
    
    for (int i=(N-1); i!=1; i--){
        N=(N*i);
    }

    return N;
}

//exercicio 6 
int exercicio6(const char* cstr){

    int x1 = 1, x2 = 1, x3 = 0, seq = 3, k, count;

    sscanf(cstr, "%d%n", &k, &count); cstr += count;

    while (seq<=k){
        x3=x1+x2;
        x1=x2;
        x2=x3;
        seq++;
    }

    return x3;
}


//exercicio 7
char exercicio7(const char* cstr){

    int N, count, vit_maria=0, vit_joao=0, empate = 0;
    sscanf(cstr, "%d%n", &N, &count); cstr += count;
    
    char Ma[N], Jo[N], pedra = 'd', papel = 'p', tesoura = 't';
    

    for (int i=0; i<N; i++){
        sscanf(cstr, "%s %s%n", &Ma[i], &Jo[i], &count); cstr += count;
    }
    for (int i=0; i<N+2; i++){
        if (((Ma[i]==tesoura)&&(Jo[i]==papel))||((Ma[i]==papel)&&(Jo[i]==pedra))||((Ma[i]==pedra)&&(Jo[i]==tesoura))){
            vit_maria+=1;
        }
        else if (((Jo[i]==tesoura)&&(Ma[i]==papel))||((Jo[i]==papel)&&(Ma[i]==pedra))||((Jo[i]==pedra)&&(Ma[i]==tesoura))){
            vit_joao+=1;
        }
        else if (Ma[i]==Jo[i]){
            empate+=1;
        }
    }
    if (vit_maria>vit_joao){
        return 'M';
    }
    else if (vit_maria<vit_joao){
        return 'J';
    }
    else{
        return 'X';
    }
}

//exercicio 8
tuple <int, int> exercicio8(const char* cstr){

    int A, B, aux, count;
    int *p1, *p2;

    sscanf(cstr, "%d %d%n", &A, &B, &count); cstr += count;

    p1=&A;
    p2=&B;
    aux=*p1;
    *p1=*p2;
    *p2=aux;
    
    return make_tuple(A, B);
}

//exercicio 9
float exercicio9(const char* cstr){

    int N, aux, count;
    sscanf(cstr,"%d%n", &N, &count); cstr += count;
    
    int lista[N];
    float mediana=0;
    
    for (int i=0; i<N; i++){
        sscanf(cstr, "%d%n", &lista[i], &count); cstr += count;
    }
    
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            if (lista[i]>lista[j]){
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }

    if (N%2){
        mediana=lista[N/2];
    }
    else{
        mediana=(lista[N/2-1]+lista[N/2])/2;
    }

    return mediana;
}
