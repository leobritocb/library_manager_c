#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define FIELD_SIZE 25//"define" - serve para criar/definir constantes.
#define length(array) ( sizeof (array) / sizeof (array)[i] )//"sizeof" - é um operador que faz um return do tamanho da variável em bytes.
#define limpatela()(system("cls"))//define limpa tela como uma funçao que quando chamado limpa a tela, usado para evitar estar digitando system("cls")
#define cor()(system("color f0"))

/***************************************************************************************/
//cria coordenadas para o cursor
void gotoxy(int x,int y){
COORD coord;
coord.X=(short)x;
coord.Y=(short)y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);}
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
//define tempo de exibiçao/retardo para determinado texto ou linha,etc//
void delay(unsigned int mseg){
    clock_t goal = mseg + clock();
    while (goal > clock());}
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
    void limpalinha(int linha){
    centro(linha,"                                                                                                                                                               ");
           return;}
//limpa os avisos - todos os avisos estao padronizados nas linha 19,20,21,22 e 23
void limpaavisos(void){
centro(19,"                                                                                                                                                      ");
centro(20,"                                                                                                                                                      ");
centro(21,"                                                                                                                                                      ");
centro(22,"                                                                                                                                                      ");
centro(22,"                                                                                                                                                      ");
centro(23,"                                                                                                                                                      ");}
   /* desenha linha preta completa em determinado lugar*/
    void linha(void){
        int posicao;
        for(posicao=0;posicao<170;posicao++){
            delay(-1);
            printf("%c",432);}
        return;}
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
//desenha lihas no quadro de opçoes,nessa função voce escolhe a velocidade de exibição e o tamanho da linha
void linhaq(int tam,int desenho){
    int posicao;
    for(posicao=0;posicao<tam;posicao++)
        {
            printf("%c",desenho);
        }
        return(tam,desenho);}
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
//desenha lihas em determinado lugar,nessa função voce escolhe a velocidade de exibição,o desenho ou caractere e o tamanho da linha
void linhap(int tam,int desenho,int vel){
    int posicao;
    for(posicao=0;posicao<tam;posicao++)
        {
            delay(vel);
            printf("%c",desenho);
        }
        return(tam,desenho,vel);}
void desenhatela(){
int i=7;
for(i=6;i<56;i++){
    gotoxy(0,i);linha();}}
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
   /*Centraliza um mensagem em determinada linha*/
void centro(int line,char *mensagem){
       int col;
       col=((159-strlen(mensagem))/2);
       gotoxy(col,line);
       printf(mensagem);
       return;}
cabecalho(){
    limpalinha(2);limpalinha(3);
    gotoxy(0,0);linhaq(170,475);gotoxy(0,5);linhaq(170,475);
    gotoxy(20,2);printf("Desenvolvido por:");
    gotoxy(20,3);printf("     HPL\xa9");
    gotoxy(120,2);printf("Data: ");exibedata();
    gotoxy(120,3);printf("Hora: ");exibehora();}
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
exibedata(){//exibe a data atual do sistema
struct tm *DataAtual;
time_t Segundos;
    time(&Segundos); //obtém a hora em segundos.
    DataAtual = localtime(&Segundos); //converte horas em segundos. //estrutura para armazenar data e hora.
printf("%02d/%02d/%04d", DataAtual->tm_mday, DataAtual->tm_mon+1,DataAtual->tm_year+1900);
}
exibehora(){//exibe a hora atual do sistema
struct tm *DataAtual; //estrutura para armazenar data e hora.
    time_t Segundos;
    time(&Segundos); //obtém a hora em segundos.
    DataAtual = localtime(&Segundos); //converte horas em segundos.
    printf("%02d:%02d", DataAtual->tm_hour, DataAtual->tm_min);}
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
    /* Lista de variaveis e ponteiros globais*/
    FILE *user,*func,*liv,*emp,*login;
    int i,y,j=0,num_cliente,num_func,num_liv,num_e,escolha;
    float preco;
    char opt[2],resp,tecla;
    char sistema[30]="GEST\xc7O DE BIBLIOTECA";
    char tioa=198,cedilha=135,CEDILHA=128;
    int cod_livro,cod_usuario,cod_func,dia_e,mes_e,ano_e,dia_d,mes_d,ano_d;
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*Estruturas para cadastros*/
struct CLIENTE{ //
    int cod;
    char nome[50];
    char endereco[100];
    char telefone[12];
    char rg[15];
    char cpf[12];
    char email[50];
    int excluido;
    int status;

    }; struct CLIENTE c;

struct FUNCIONARIO{
    int cod;
    char nome[50];
    char cargo[20];
    char rm[11];
    char rg[15];
    char cpf[11];
    int excluido;
    }; struct FUNCIONARIO f;

struct LIVRO{
    int cod;
    char titulo[50];
    char autor[50];
    char editora[30];
    char edicao[10];
    char tema[20];
    char isbn[13];
    int quant;
    float preco;
    int excluido;
    }; struct LIVRO book;

struct EMPRESTIMO{
    int cod;
    int livro,usuario,func;
    int empdia,empmes,empano,devdia,devmes,devano,diadevolvido,mesdevolvido,anodevolvido;
    int quant;
    int excluido;
    int devolvido;
    }; struct EMPRESTIMO e;

struct DATA{
    int dia,mes,ano};

struct conta {
        //"struct" - passa o char id e char password tornando estes um so objecto.
  char *id;
  char *password;
};

static struct conta conta[] =
{
        // "static struct" - faz com que os membros desta classe sejam estáticos.
    {"Admin", "Admin"},
    {"hpl", "hpl"},
};

/**XXXXXXXXXXXXXXXX MANIPULANDO DATAS XXXXXXXXXXXXXXXXXXXXXX*/

void recebeData(char str[9], struct DATA *Alvo){//recebe data do sistema
	// 0, 1 = mes
	// 2    = /
	// 3, 4 = dia
	// 5    = /
	// 6, 7 = ano
	// 8    = NULO
	char _dia[3] = {
		str[3],
		str[4],
		0
	};
	char _mes[3] = {
		str[0],
		str[1],
		0
	};
	char _ano[3] = {
		str[6],
		str[7],
		0
	};
	Alvo->dia = atoi(_dia);
	Alvo->mes = atoi(_mes);
	Alvo->ano = atoi(_ano);
	return;
}
int somadatadia(int d,int m, int a,int diase){//soma duas datas e retorna o dia
	int dv,mv,av,aux;
	if(m==2){
		if((a%4==0)&&(a%100!=0)||(a%400==0))
		aux=29;
		else
		aux=28;}
	else{
		if(m==4||m==6||m==9||m==11)
		aux=30;
		else
		aux=31;}
		dv=d+diase;
		if(dv>aux){
			dv=dv-aux;
			mv=m+1;
			if(mv>12){
				mv=1;
				av=a+1;}
		}
		else{
			mv=m;
			av=a;
		}return(dv);
	}
int somadatames(int d,int m, int a,int diase){//soma duas datas e retorna o mes
	int dv,mv,av,aux;
	if(m==2){
		if((a%4==0)&&(a%100!=0)||(a%400==0))
		aux=29;
		else
		aux=28;}
	else{
		if(m==4||m==6||m==9||m==11)
		aux=30;
		else
		aux=31;}
		dv=d+diase;
		if(dv>aux){
			dv=dv-aux;
			mv=m+1;
			if(mv>12){
				mv=1;
				av=a+1;}
		}
		else{
			mv=m;
			av=a;
		}return(mv);
	}
int somadataano(int d,int m, int a,int diase){//soma duas datas e retorna o ano
	int dv,mv,av,aux;
	av=a;
	if(m==2){
		if((a%4==0)&&(a%100!=0)||(a%400==0))
		aux=29;
		else
		aux=28;}
	else{
		if(m==4||m==6||m==9||m==11)
		aux=30;
		else
		aux=31;}
		dv=d+diase;
		if(dv>aux){
			dv=dv-aux;
			mv=m+1;
			if(mv>12){
				mv=1;
				av=a+1;}
		}
		else{
			mv=m;
		}return(av);
	}
/**XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
//exibe a tela principal
void tela_principal(void){
        char opcao;
        system("title GESTÃO DE BIBLIOTECA");limpatela();
        if ((user=fopen("USER.DAT","rb+"))==NULL){//abre o arquivo para usuario, se não existir cria um escrita e leitura
            user=fopen("USER.DAT","wb+");
            fwrite(&c,sizeof(struct CLIENTE),1,user);}
        if ((func=fopen("FUNC.DAT","rb+"))==NULL){//abre o arquivo para funcionario, se não existir cria um para escrita e leitura
            func=fopen("FUNC.DAT","wb+");
            fwrite(&f,sizeof(struct FUNCIONARIO),1,func);}
        if ((liv=fopen("LIV.DAT","rb+"))==NULL){//abre o arquivo para livros, se não existir cria um para escrita e leitura
            liv=fopen("LIV.DAT","wb+");
            fwrite(&book,sizeof(struct LIVRO),1,liv);}
        do{
            cabecalho();//desenhatela();
            centro(2,sistema);
            centro(3,"Menu Principal\n\n");
            gotoxy(60,7);linhaq(37,475);
            gotoxy(60,8);printf("\xdb                                   \xdb");
            gotoxy(60,9);printf("\xdb.....[1]-> Leitor..................\xdb");
            gotoxy(60,10);printf("\xdb                                   \xdb");
            gotoxy(60,11);printf("\xdb.....[2]-> Funcionario.............\xdb");
            gotoxy(60,12);printf("\xdb                                   \xdb");
            gotoxy(60,13);printf("\xdb.....[3]-> Livros..................\xdb");
            gotoxy(60,14);printf("\xdb                                   \xdb");
            gotoxy(60,15);printf("\xdb.....[4]-> Emprestimos.............\xdb");
            gotoxy(60,16);printf("\xdb                                   \xdb");
            gotoxy(60,17);printf("\xdb.....[0]-> Finalizar/Salvar........\xdb");
            gotoxy(60,18);printf("\xdb                                   \xdb");
            gotoxy(60,19);printf("\xdb..........Escolha uma op%c%co:[   ]..\xdb",cedilha,tioa);
            gotoxy(60,20);printf("\xdb                                   \xdb");
            gotoxy(60,21);linhaq(37,475);
            gotoxy(91,19);fflush(stdin);opcao=getche();
            switch(opcao){
        case '1':
            tela_leitor();break;
        case '2':
            tela_f();break;
        case '3':
            tela_livro();break;
        case '4':
            tela_e();break;}
        }while(opcao!='0');
            fclose(user);fclose(func);fclose(liv);
            limpatela();centro(10,"Salvando........\n\n");gotoxy(50,11);linhap(60,475,10);
            limpatela();centro(10,"Salvo com sucesso\n");Sleep(5000);
            /*fflush(stdin);while((tecla=getchar())!='\n')*/exit(0);
}
/**************** Rotinas e funções para LEITOR ***** CONCLUIDO **************************************/
void tela_leitor(void){
    /*Verifica a existencia do arquivo, se não existir cria*/
        char op1;
        do{
            limpatela();cabecalho();//desenhatela();
            centro(2,sistema);
            centro(3," Menu Leitor  \n");
            gotoxy(60,7);linhaq(37,475);
            gotoxy(60,8);printf("\xdb                                   \xdb");
            gotoxy(60,9);printf("\xdb.....[1]-> Incluir.................\xdb");
            gotoxy(60,10);printf("\xdb                                   \xdb");
            gotoxy(60,11);printf("\xdb.....[2]-> Pesquisar/Editar........\xdb");
            gotoxy(60,12);printf("\xdb                                   \xdb");
            gotoxy(60,13);printf("\xdb.....[3]-> Listar..................\xdb");
            gotoxy(60,14);printf("\xdb                                   \xdb");
            gotoxy(60,15);printf("\xdb.....[4]-> Excluir.................\xdb");
            gotoxy(60,16);printf("\xdb                                   \xdb");
            gotoxy(60,17);printf("\xdb.....[0]-> Voltar..................\xdb");
            gotoxy(60,18);printf("\xdb                                   \xdb");
            gotoxy(60,19);printf("\xdb..........Escolha uma op%c%co:[   ]..\xdb",cedilha,tioa);
            gotoxy(60,20);printf("\xdb                                   \xdb");
            gotoxy(60,21);linhaq(37,475);
            gotoxy(91,19);fflush(stdin);op1=getche();
            switch(op1){
        case '1':
            incluir();break;
        case '2':
            escolha=0;pesquisar();break;
        case '3':
            listar_leitor();break;
        case '4':
            escolha=1;pesquisar();break;
            }
        }while(op1!='0');tela_principal();
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
   /*tela para cadastro/pesquisa/exclusao do usuario*/
    void tela_cadastro_leitor(void){
        limpalinha(10);
        limpalinha(11);
        limpalinha(12);
        limpalinha(13);
        limpalinha(14);
        limpalinha(15);
        limpalinha(16);
        limpalinha(17);
        gotoxy(60,10);printf("Codigo......:");
        gotoxy(60,11);printf("Nome........:");
        gotoxy(60,12);printf("Endere%co....:",cedilha);
        gotoxy(60,13);printf("Telefone....:");
        gotoxy(60,14);printf("RG..........:");
        gotoxy(60,15);printf("CPF.........:");
        gotoxy(60,16);printf("Email.......:");
        return;}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
    /*Mostra os dados quando há pesquisa ou tentativa de cadastro para usuario existente*/
    void exibedados(void){
        gotoxy(77,10);printf("                                   ");
        gotoxy(77,10);printf("%d",num_cliente);
        gotoxy(77,11);printf("%s",c.nome);
        gotoxy(77,12);printf("%s",c.endereco);
        gotoxy(77,13);printf("%s",c.telefone);
        gotoxy(77,14);printf("%s",c.rg);
        gotoxy(77,15);printf("%s",c.cpf);
        gotoxy(77,16);printf("%s",c.email);
        gotoxy(60,17);printf("Status......:");
        if(c.status!=1){gotoxy(77,17);printf("Disponivel");}
        else{gotoxy(77,17);printf("Com Emprestimo");}
        return;
    }
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/* Pesquisa se o codigo ja esta cadastrado ou nao*/
int pesquisa(int NUM){
    int achou=0;
    rewind(user);
    while(!feof(user)&&achou!=1){
        fread(&c,sizeof(struct CLIENTE),1,user);
        if(NUM==c.cod)//se achar o codigo retorna 1, se nao achar retorna 0
            achou=1;
    }return(achou);
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/*Exclui cadastro do usuario / Cria uma arquivo auxilar e copia os dados do original para o auxiliar,*/
int excluir(int NUM){
    FILE *aux;//cria um ponteiro auxiliar
    fclose(user);
    gotoxy(60,20);system("copy USER.DAT UDADOS.DAT");//copia os dados do arquivo que contem os usuario para um arquivo auxiliar
    limpaavisos();
    gotoxy(20,20);system("del USER.DAT");//apaga o arquivo de usuarios
    user=fopen("USER.DAT","wb+");//abre novo arquivo
    aux=fopen("UDADOS.DAT","rb+");//abre novo arquio auxiliar
    rewind(aux);
    while(!feof(aux)){
        fread(&c,sizeof(struct CLIENTE),1,aux);
        if (NUM!=c.cod)//codigos cadastrados diferente do argumento sao copiados
            fwrite(&c,sizeof(struct CLIENTE),1,user);

    }fclose(aux);
    system("del UDADOS.DAT");//apaga arquivo auxiliar
    centro(21,"Leitor excluido. Pressione [ENTER] para continuar");
    fflush(stdin);while((tecla=getchar())!='\n')gotoxy(53,21);
    return(0);
}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
void incluir(void){
    limpatela();cabecalho();centro(2,sistema);
    centro(3," Incluir Leitor \n");printf("\n");
    centro(5," Digite os dados ");
    do{
        limpaavisos();
        codmaior1000://goto
        naosalvar:
        centro(23,"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Digite [0] para voltar ao menu \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        tela_cadastro_leitor();
        gotoxy(77,10);fflush(stdin);scanf("%d",&num_cliente);
        limpaavisos();
        /*if(num_cliente>999){
            centro(20,"\aCodigo n\xc6o permitido");
            centro(21,"Tecle [ENTER] para nova tentativa");
            fflush(stdin);while((tecla=getchar())!='\n')gotoxy(50,23);
            limpaavisos();
            goto codmaior1000;}*/
        if (num_cliente!=0){
                if (pesquisa(num_cliente)==1){//se achar o codigo retorna 1
            exibedados();// exibe os dados do codigo pesquisado se encontrado
            if(c.excluido!=1){limpalinha(20);
            centro(20,"\aEste Leitor ja existe!");}
            else{limpalinha(20);
                centro(20,"\aEste Leitor foi excluido!");}
            centro(21,"Tecle [ENTER] para nova tentativa");
            fflush(stdin);while((tecla=getchar())!='\n')gotoxy(50,23);limpalinha(22);}
        else{
            fseek(user,(long)sizeof(struct CLIENTE),2);
            gotoxy(77,11);
            fflush(stdin);fgets(c.nome,50,stdin);
            gotoxy(77,12);
            fflush(stdin);fgets(c.endereco,100,stdin);
            gotoxy(77,13);
            fflush(stdin);fgets(c.telefone,12,stdin);
            gotoxy(77,14);
            fflush(stdin);fgets(c.rg,15,stdin);
            gotoxy(77,15);
            fflush(stdin);fgets(c.cpf,12,stdin);
            gotoxy(77,16);
            fflush(stdin);fgets(c.email,50,stdin);
            c.cod=num_cliente;
            c.excluido=0;
            c.status=0;enter:limpaavisos();
            centro(21,"Deseja salvar este Leitor [S/N]?");fflush(stdin);fgets(opt,2,stdin);
                        if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){goto naosalvar;}
                        else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        limpaavisos();fwrite(&c,sizeof(struct CLIENTE),1,user);centro(20,"Leitor Salvo");}
                    else{
                    limpalinha(21);centro(21,"Digite [S ou N] | Pressione [ENTER] para continuar");
                    while((tecla=getchar())!='\n')gotoxy(53,23);goto enter;}
        }
        }
    }
    while(num_cliente!=0);}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/

void listar_leitor(void){
    int i=5;
    int cesp=442,ini=442,fim=442,a=461;
    rewind(user);
    limpatela();
    centro(1,"Lista de Leitores");
    gotoxy(0,2);linhap(80,461,0);gotoxy(0,2);printf("%c",457);gotoxy(79,2);printf("%c",443);gotoxy(4,2);printf("%c",459);gotoxy(17,2);printf("%c",459);gotoxy(30,2);printf("%c",459);gotoxy(42,2);printf("%c",459);gotoxy(55,2);printf("%c",459);gotoxy(67,2);printf("%c",459);
    gotoxy(0,3);printf("%cCOD%c",ini,cesp);gotoxy(5,3);printf("    NOME    %c",cesp);gotoxy(18,3);printf("  ENDERE%cO  %c",CEDILHA,cesp);gotoxy(31,3);printf(" TELEFONE  %c",cesp);gotoxy(43,3);printf("     RG     %c",cesp);gotoxy(56,3);printf("    CPF    %c",cesp);gotoxy(68,3);printf("   EMAIL   %c",fim);
    gotoxy(0,4);linhap(80,461,0);gotoxy(0,4);printf("%c",460);gotoxy(4,4);printf("%c",462);gotoxy(17,4);printf("%c",462);gotoxy(30,4);printf("%c",462);gotoxy(42,4);printf("%c",462);gotoxy(55,4);printf("%c",462);gotoxy(67,4);printf("%c",462);gotoxy(79,4);printf("%c",441);
    while(fread(&c,sizeof(struct CLIENTE),1,user)==1){//usuarios com valor 0 não existe, lista todos os usuario cadastrados
        if(c.cod==0)//teste logica para não exibir o codigo 0, codigo reservado para saida de telas
        limpalinha(i);
        else{
            gotoxy(0,i);printf("%c",cesp);gotoxy(1,i);printf("%d",c.cod);gotoxy(4,i);printf("%c",cesp);gotoxy(5,i);printf("%s",c.nome);gotoxy(17,i);printf("%c",cesp);gotoxy(18,i);printf("%s",c.endereco);gotoxy(30,i);printf("%c",cesp);gotoxy(31,i);printf("%s",c.telefone);gotoxy(42,i);printf("%c",cesp);gotoxy(43,i);printf("%s",c.rg);gotoxy(55,i);printf("%c",cesp);gotoxy(56,i);printf("%s",c.cpf);gotoxy(67,i);printf("%c",cesp);gotoxy(68,i);printf("%s",c.email);gotoxy(79,i);printf("%c",fim);
            i++;
            }

}gotoxy(0,i);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",456,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,444);
centro(i+2,"Pressione [ENTER] para Voltar ao Menu Leitor");fflush(stdin);while((tecla=getchar())!='\n')gotoxy(23,i+2);tela_leitor();}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
/* faz a pesquisa exibindo o usuarios*/
pesquisar(void){
    limpatela();cabecalho();
    centro(2,sistema);
    printf("\n\n");
    gotoxy(60,6);printf("Codigo:");
    do{
        centro(3,"Pesquisa Leitor");
        limpaavisos();
        centro(23,"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Digite [0] para voltar ao menu de usuario \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        tela_cadastro_leitor();
        gotoxy(68,6);printf("                          ");
        gotoxy(68,6);fflush(stdin);scanf("%d",&num_cliente);
        limpaavisos();
        if (num_cliente!=0){
            i=pesquisa(num_cliente);
            if(i==1&&c.excluido==0){
                exibedados();
                alterar:limpalinha(23);
                    if (escolha==0){
                            centro(21,"Deseja editar este Leitor [S/N]?...:");fflush(stdin);fgets(opt,2,stdin);
                            if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                            else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                            limpalinha(3);cabecalho();centro(3,"Editar Leitor\n\n");centro(2,sistema);editar();}
                    else{
                    limpalinha(21);centro(19,"Digite S ou N!!! Pressione [ENTER] para nova tentativa");
                    while((tecla=getchar())!='\n')gotoxy(53,23);goto alterar;}
            }else {
                limpalinha(3);cabecalho();centro(3,"Excluir Leitor");centro(2,sistema);
                limpalinha(21);centro(21,"Deseja excluir esse Leitor [S/N]?");fflush(stdin);fgets(opt,2,stdin);
                if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                limpalinha(21);excluir(num_cliente);
        }else{
        limpalinha(21);centro(21,"Digite S ou N | Pressione [ENTER] para nova tentativa");
        while((tecla=getchar())!='\n')goto alterar;
        }
        }
        limpalinha(21);centro(21,"Pressione [ENTER] para nova tentativa");
        fflush(stdin);while((tecla=getchar())!='\n');gotoxy(33,23);

    }
    else{
        if(c.excluido!=1)
        centro(20,"\aEste Leitor n\xc6o esta cadastrado!");
        else{
            centro(20,"\aEste Leitor foi excluido");exibedados();}
        limpalinha(21);centro(21,"Pressione [ENTER] para nova tentativa");
        fflush(stdin);while((tecla=getchar())!='\n')limpalinha(19);}
    }
    }while(num_cliente!=0);
    return(0);}
/*XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX*/
int editar(void){
    char op;
    int achou=2;
    do{
        limpaavisos();
        centro(23," [1]Nome [2]Endere\x87o [3]Telefone [4]RG [5]CPF [6]Email [7]Confirma [8]Abandona ");
        fflush(stdin);op=getche();
        switch(op){

            case '1':
                gotoxy(77,11);printf("                                          ");gotoxy(77,11);
                fflush(stdin);fgets(c.nome,50,stdin);
                break;
            case '2':
                gotoxy(77,12);printf("                                          ");gotoxy(77,12);
                fflush(stdin);fgets(c.endereco,100,stdin);
                break;
            case '3':
                gotoxy(77,13);printf("                                          ");gotoxy(77,13);
                fflush(stdin);fgets(c.telefone,12,stdin);
                break;
            case '4':
                gotoxy(77,14);printf("                                          ");gotoxy(77,14);
                fflush(stdin);fgets(c.rg,15,stdin);
                break;
            case '5':
                gotoxy(77,15);printf("                                          ");gotoxy(77,15);
                fflush(stdin);fgets(c.cpf,12,stdin);
                break;
            case '6':
                gotoxy(77,16);printf("                                          ");gotoxy(77,16);
                fflush(stdin);fgets(c.email,50,stdin);
                break;
            case '7':
                Confirma:
                    limpaavisos();
                    centro(21,"Confirma a edi\x87\xc6o [S/N]?...:");fflush(stdin);fgets(opt,2,stdin);
                    if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                    else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        achou=0;}
                    else{
                        limpaavisos();
                        centro(21,"Digite S ou N | Pressione [ENTER] para nova tentativa");
                        while((tecla=getchar())!='\n')
                            gotoxy(123,19);
                        goto Confirma;}break;
            case '8':
                Cancela:limpaavisos();
                    centro(21,"Abandonar edi\x87\xc6o? [S/N]...:");fflush(stdin);fgets(opt,2,stdin);
                    if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                    else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        achou=1;}
                    else{
                        limpaavisos();
                        centro(21,"Digite S ou N | Pressione [ENTER] para nova tentativa");
                        while((tecla=getchar())!='\n')gotoxy(53,19);goto Cancela;}break;}
        gotoxy(71,23);printf("     ");
    }while(achou!=0&&achou!=1);
    limpaavisos();
    if(achou==0){
        fseek(user,-(long)sizeof(struct CLIENTE),1);
        fwrite(&c,sizeof(struct CLIENTE),1,user);
        centro(21,"\aAltera\x87\xc6o bem sucedida| Pressione [ENTER] para continuar");}
    else{
            centro(21,"Sem altera\x87\xc6o | Pressione [ENTER] para continuar");}
            fflush(stdin);while((tecla=getchar())!='\n')gotoxy(33,23);limpalinha(33);
    return(0);}

/****************** Rotinas e funções FUNCIONARIO ***** Concluido ************************/
void tela_f(void){
        char op1;
        system("title GESTÃO DE BIBLIOTECA");
        do{
            limpatela();cabecalho();//desenhatela();
            centro(2,sistema);
            centro(3,"Menu Funcionario\n");
            gotoxy(60,7);linhaq(37,475);
            gotoxy(60,8);printf("\xdb                                   \xdb");
            gotoxy(60,9);printf("\xdb.....[1]-> Incluir.................\xdb");
            gotoxy(60,10);printf("\xdb                                   \xdb");
            gotoxy(60,11);printf("\xdb.....[2]-> Pesquisar/Editar........\xdb");
            gotoxy(60,12);printf("\xdb                                   \xdb");
            gotoxy(60,13);printf("\xdb.....[3]-> Listar..................\xdb");
            gotoxy(60,14);printf("\xdb                                   \xdb");
            gotoxy(60,15);printf("\xdb.....[4]-> Excluir.................\xdb");
            gotoxy(60,16);printf("\xdb                                   \xdb");
            gotoxy(60,17);printf("\xdb.....[0]-> Voltar..................\xdb");
            gotoxy(60,18);printf("\xdb                                   \xdb");
            gotoxy(60,19);printf("\xdb..........Escolha uma op%c%co:[   ]..\xdb",cedilha,tioa);
            gotoxy(60,20);printf("\xdb                                   \xdb");
            gotoxy(60,21);linhaq(37,475);
            gotoxy(91,19);op1=getche();fflush(stdin);
            switch(op1){
        case '1':
            incluir_f();break;
        case '2':
            escolha=0;pesquisar_f();break;
        case '3':
            listar_funcionario();break;
        case '4':
            escolha=1;pesquisar_f();break;

            }
        }while(op1!='0');tela_principal();}
/*********************************************************************************************************/
   /*tela para menu do funcionario*/
void tela_cadastro_f(void){
        limpalinha(10);
        limpalinha(11);
        limpalinha(12);
        limpalinha(13);
        limpalinha(14);
        limpalinha(15);
        gotoxy(60,10);printf("Codigo......:");
        gotoxy(60,11);printf("Nome........:");
        gotoxy(60,12);printf("Cargo.......:");
        gotoxy(60,13);printf("CRM.........:");
        gotoxy(60,14);printf("RG..........:");
        gotoxy(60,15);printf("CPF.........:");
        return;}

/********************************************************************************************************/
    /*Mostra os dados quando há pesquisa ou tentativa de cadastro do funcionario*/

void exibedados_f(void){
        gotoxy(77,10);printf("%d",num_func);
        gotoxy(77,11);printf("%s",f.nome);
        gotoxy(77,12);printf("%s",f.cargo);
        gotoxy(77,13);printf("%s",f.rm);
        gotoxy(77,14);printf("%s",f.rg);
        gotoxy(77,15);printf("%s",f.cpf);
        return;
    }

/**********************************************************************************************************/
/*Pesquisa se existe algum funcionario cadastrado com o codigo*/
int pesquisa_f(int NUM){
    int achou=0;
    rewind(func);
    while(!feof(func)&&achou!=1){
        fread(&f,sizeof(struct FUNCIONARIO),1,func);
        if(NUM==f.cod)
            achou=1;
    }return(achou);
}

/*******************************************************************************************************/
/*Exclui cadastro do funcionario*/
int excluir_f(int NUM){
    FILE *aux;//cria um ponteiro auxiliar
    fclose(func);
    gotoxy(60,20);system("copy FUNC.DAT DADOS.DAT");//copia os dados do arquivo que contem os usuario para um arquivo auxiliar
    limpaavisos();
    gotoxy(20,20);system("del FUNC.DAT");//apaga o arquivo de usuarios
    limpaavisos();
    user=fopen("FUNC.DAT","wb+");
    aux=fopen("DADOS.DAT","rb+");
    rewind(aux);
    while(!feof(aux)){
        fread(&f,sizeof(struct FUNCIONARIO),1,aux);
        if (NUM!=f.cod)
            fwrite(&f,sizeof(struct FUNCIONARIO),1,func);
    }fclose(aux);
    system("del DADOS.DAT");//apaga arquivo auxiliar
    limpaavisos();
    centro(21,"Funcionario excluido. Pressione [ENTER] para continuar");
    fflush(stdin);while((tecla=getchar())!='\n')gotoxy(53,21);return(0);}
/****************************************************************************************************/
/* Inclui novos funcionarios */
int incluir_f(void){
    limpatela();cabecalho();
    centro(2,sistema);
    centro(3,"Incluir Funcionario\n");
    printf("\n");
    centro(5," Digite os dados ");
    do{
        limpaavisos();
        codmaior1000:
        naosalvar:
        centro(23,"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Digite [0] para voltar ao menu \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        tela_cadastro_f();
        gotoxy(77,10);fflush(stdin);
        scanf("%d",&num_func);
        limpaavisos();
        if(num_func>999){
            centro(20,"\aCodigo n\xc6o permitido");
            centro(21,"Tecle [ENTER] para nova tentativa");
            fflush(stdin);while((tecla=getchar())!='\n')gotoxy(50,23);
            limpaavisos();
            goto codmaior1000;}
        if (num_func!=0){
                if (pesquisa_f(num_func)==1){
            exibedados_f();
            if(f.excluido!=1)centro(20,"\aEste funcionario ja existe");
            else centro(20,"\aEste funcionario foi exluido\n");
            centro(21,"Tecle [ENTER] para nova tentativa");
            fflush(stdin);while((tecla=getchar())!='\n')gotoxy(33,21);
            limpaavisos();}
        else{
            fseek(func,(long)sizeof(struct FUNCIONARIO),2);
            gotoxy(77,11);
            fflush(stdin);fgets(f.nome,50,stdin);
            gotoxy(77,12);
            fflush(stdin);fgets(f.cargo,20,stdin);
            gotoxy(77,13);
            fflush(stdin);fgets(f.rm,11,stdin);
            gotoxy(77,14);
            fflush(stdin);fgets(f.rg,15,stdin);
            gotoxy(77,15);
            fflush(stdin);fgets(f.cpf,11,stdin);
            f.cod=num_func;
            f.excluido=0;
            centro(21,"Deseja salvar este funcionario [S/N]?");fflush(stdin);fgets(opt,2,stdin);
                        if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){goto naosalvar;}
                        else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        limpaavisos();fwrite(&f,sizeof(struct FUNCIONARIO),1,func);centro(20,"Funcionario Salvo");}
                    else{
                    limpalinha(21);centro(21,"Digite [S ou N] | Pressione [ENTER] para continuar");
                    while((tecla=getchar())!='\n')gotoxy(53,23);}
            }
        }
    }
    while(num_func!=0);
    return(0);
}
/*************************************************************************************/
void listar_funcionario(void){

    int i=5;
    int cesp=442,ini=442,fim=442,a=461;
    rewind(func);
    limpatela();
    centro(1,"Lista de Funcionarios");
    gotoxy(0,2);linhap(80,461,0);gotoxy(0,2);printf("%c",457);gotoxy(4,2);printf("%c",459);gotoxy(22,2);printf("%c",459);gotoxy(38,2);printf("%c",459);gotoxy(52,2);printf("%c",459);gotoxy(66,2);printf("%c",459);gotoxy(79,2);printf("%c",187);
    gotoxy(0,3);printf("%cCOD%c",ini,cesp);gotoxy(5,3);printf("       NOME      %c",cesp);gotoxy(23,3);printf("     CARGO     %c",cesp);gotoxy(39,3);printf("      RM     %c",cesp);gotoxy(53,3);printf("      RG     %c",cesp);gotoxy(67,3);printf("     CPF    %c",fim);
    gotoxy(0,4);linhap(80,461,0);gotoxy(0,4);printf("%c",460);gotoxy(4,4);printf("%c",462);gotoxy(22,4);printf("%c",462);gotoxy(38,4);printf("%c",462);gotoxy(52,4);printf("%c",462);gotoxy(66,4);printf("%c",462);gotoxy(79,4);printf("%c",441);
    while(fread(&f,sizeof(struct FUNCIONARIO),1,func)==1){//usuarios com valor 0 não existe, lista todos os usuario cadastrados
        if(f.cod==0)//teste logica para não exibir o codigo 0, codigo reservado para saida de telas
        limpalinha(i);
        else{
            gotoxy(0,i);printf("%c",cesp);gotoxy(1,i);printf("%d",f.cod);gotoxy(4,i);printf("%c",cesp);gotoxy(5,i);printf("%s",f.nome);gotoxy(22,i);printf("%c",cesp);gotoxy(23,i);printf("%s",f.cargo);gotoxy(38,i);printf("%c",cesp);gotoxy(39,i);printf("%s",f.rm);gotoxy(52,i);printf("%c",cesp);gotoxy(53,i);printf("%s",f.rg);gotoxy(66,i);printf("%c",cesp);gotoxy(67,i);printf("%s",f.cpf);gotoxy(79,i);printf("%c",fim);
            i++;
            }

}gotoxy(0,i);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",456,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,444);
centro(i+2,"Pressione [ENTER] para Voltar ao Menu Funcionario");fflush(stdin);while((tecla=getchar())!='\n')gotoxy(23,i+2);tela_f();
}
/**************************************************************************************************************/
/* Pesquisa funcionario por codigo*/
pesquisar_f(void){
    limpatela();cabecalho();
    centro(2,sistema);
    centro(3,"Funcionario\n\n");
    gotoxy(60,6);printf("Codigo: ");
    do{
        limpaavisos();
        centro(23,"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Digite [0] para voltar ao menu do funcionario \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        tela_cadastro_f();
        gotoxy(68,6);printf("                        ");
        gotoxy(68,6);fflush(stdin);scanf("%d",&num_func);
        if (num_func!=0){
            y=pesquisa_f(num_func);
            if(y==1&&f.excluido==0){
                exibedados_f();
                alterar:
                    limpalinha(21);
                    if (escolha==0){
                        limpalinha(21);centro(21,"Deseja editar este funcionario [S/N]?");fflush(stdin);fgets(opt,2,stdin);
                        if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                        else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                            limpaavisos();cabecalho();centro(3,"Editar Funcionario");
                            editar_f();
                        }
                    else{
                    limpalinha(21);centro(21,"Digite [S ou N] | Pressione enter para continuar");
                    while((tecla=getchar())!='\n')
                        gotoxy(53,23);
                        goto alterar;
                    }
            }else {
        limpalinha(21);centro(21,"Deseja excluir este funcionario [S/N]?");fflush(stdin);fgets(opt,2,stdin);
        if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
        else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
            limpaavisos();cabecalho();centro(3,"Excluir Funcionario");
            excluir_f(num_func);
        }else{
        limpalinha(21);centro(21,"Digite [S ou N] | Pressione [ENTER] para continuar");
        fflush(stdin);while((tecla=getchar())!='\n')limpalinha(21);gotoxy(53,23);goto alterar;
        }
        }
        limpalinha(21);centro(21,"Pressione [ENTER] para nova tentativa");
        fflush(stdin);while((tecla=getchar())!='\n')limpalinha(21);gotoxy(33,23);

    }
    else{
        limpalinha(20);
        if(f.excluido!=1)
        centro(20,"\aEste funcionario nao esta cadastrado!");
        else{
            centro(20,"\aEste funcionario foi excluido!");
            exibedados_f();
        }
        limpalinha(21);centro(21,"Pressione [ENTER] para nova tentativa");
        fflush(stdin);while((tecla=getchar())!='\n')gotoxy(37,23);
        limpaavisos();
    }
    }
    }while(num_func!=0);
    return(0);
}

/**********************************************************************************************************************/
/*Edita funcionario*/
int editar_f(void){
    char op;
    int achou=2;
    do{
        limpaavisos();centro(23,"[1]Nome [2]Cargo [3]RM [4]RG [5]CPF [6]Confirma [7]Abandona:");
        fflush(stdin);op=getchar();
        switch(op){

            case '1':
                gotoxy(77,11);printf("                                          ");gotoxy(77,11);
                fflush(stdin);fgets(f.nome,50,stdin);
                break;
            case '2':
                gotoxy(77,12);printf("                                          ");gotoxy(77,12);
                fflush(stdin);fgets(f.cargo,20,stdin);
                break;
            case '3':
                gotoxy(77,13);printf("                                          ");gotoxy(77,13);
                fflush(stdin);fgets(f.rm,11,stdin);
                break;
            case '4':
                gotoxy(77,14);printf("                                          ");gotoxy(77,14);
                fflush(stdin);fgets(f.rg,15,stdin);
                break;
            case '5':
                gotoxy(77,15);printf("                                          ");gotoxy(77,15);
                fflush(stdin);fgets(f.cpf,11,stdin);
                break;
            case '6':
                Confirma:
                    limpalinha(21);centro(21,"Confirma a edi\x87\xc6o [S/N]?: ");
                    fflush(stdin);fgets(opt,2,stdin);
                    if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                    else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        achou=0;
                    }
                    else{
                        limpalinha(21);centro(21,"Digite [S ou N] | Pressione [ENTER] para continuar");
                        while((tecla=getchar())!='\n')gotoxy(53,23);goto Confirma;
                    }
                    break;
            case '7':
                Cancela:
                    limpalinha(21);centro(21,"Abandonar edi\x87\xc6o? [S/N]");fflush(stdin);fgets(opt,2,stdin);
                    if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                    else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        achou=1;
                    }
                    else{
                        limpalinha(21);centro(21,"Digite [S ou N] | Pressione [ENTER] para continuar");
                        while((tecla=getchar())!='\n')gotoxy(53,23);goto Cancela;
                    }
                    break;

        }
        gotoxy(71,23);printf("     ");
    }while(achou!=0&&achou!=1);
    gotoxy(1,23);
    if(achou==0){
        fseek(func,-(long)sizeof(struct FUNCIONARIO),1);
        fwrite(&f,sizeof(struct FUNCIONARIO),1,func);
        limpalinha(21);centro(21,"\aAltera\x87\xc6o bem sucedida| Pressione [ENTER] para continuar");
    }
    else{
            centro(21,"Sem altera\x87\xc6o | Pressione [ENTER] para continuar");
            }
            fflush(stdin);while((tecla=getchar())!='\n')gotoxy(33,23);limpaavisos();
    return(0);
}
/******************** ROTINAS E FUNÇÕES LIVROS ************************************************/

/**Tela para menu do livro */
void tela_livro(void){/*Verifica a existencia do arquivo, se não existir cria*/
	char op1;
	system("title GESTÃO DE BIBLIOTECA");
	do{
		limpatela();cabecalho();//desenhatela();
		centro(2,sistema);
		centro(3," Menu Livro  \n");
		gotoxy(60,7);linhaq(37,475);
		gotoxy(60,8);printf("\xdb                                   \xdb");
		gotoxy(60,9);printf("\xdb.....[1]-> Incluir.................\xdb");
		gotoxy(60,10);printf("\xdb                                   \xdb");
		gotoxy(60,11);printf("\xdb.....[2]-> Pesquisar/Editar........\xdb");
		gotoxy(60,12);printf("\xdb                                   \xdb");
		gotoxy(60,13);printf("\xdb.....[3]-> Listar..................\xdb");
		gotoxy(60,14);printf("\xdb                                   \xdb");
		gotoxy(60,15);printf("\xdb.....[4]-> Excluir.................\xdb");
		gotoxy(60,16);printf("\xdb                                   \xdb");
		gotoxy(60,17);printf("\xdb.....[0]-> Voltar..................\xdb");
		gotoxy(60,18);printf("\xdb                                   \xdb");
		gotoxy(60,19);printf("\xdb..........Escolha uma op%c%co:[   ]..\xdb",cedilha,tioa);
		gotoxy(60,20);printf("\xdb                                   \xdb");
		gotoxy(60,21);linhaq(37,475);
		gotoxy(91,19);fflush(stdin);op1=getche();
		switch(op1){
        case '1':
            incluir_livro();break;
        case '2':
            escolha=0;pesquisar_livro();break;
        case '3':
            listar_livro();break;
        case '4':
            escolha=1;pesquisar_livro();break;}
	}while(op1!='0');tela_principal();}
/**************** Tela de Cadastro/Pesquisa/Exclusão de Livros **************************************/

void tela_cadastro_livro(void){
    limpalinha(10);
    limpalinha(11);
    limpalinha(12);
    limpalinha(13);
    limpalinha(14);
    limpalinha(15);
    limpalinha(16);
    limpalinha(17);
    limpalinha(18);
	gotoxy(60,10);printf("Codigo......:");
	gotoxy(60,11);printf("Titulo......:");
    gotoxy(60,12);printf("Autor.......:");
    gotoxy(60,13);printf("Editora.....:");
    gotoxy(60,14);printf("Edi%c%co......:",cedilha,tioa);
    gotoxy(60,15);printf("Tema........:");
    gotoxy(60,16);printf("ISBN........:");
    gotoxy(60,17);printf("Quantidade..:");
    gotoxy(60,18);printf("Pre%co.......:",cedilha);
    return;
}

/******************** Exibe dados em Inclusão existente/pesquisa/exclusão ****************************/
void exibedados_livro(void){
    gotoxy(77,10);printf("%d",num_liv);
    gotoxy(77,11);printf("%s",book.titulo);
    gotoxy(77,12);printf("%s",book.autor);
    gotoxy(77,13);printf("%s",book.editora);
    gotoxy(77,14);printf("%s",book.edicao);
    gotoxy(77,15);printf("%s",book.tema);
    gotoxy(77,16);printf("%s",book.isbn);
    gotoxy(77,17);printf("%d",book.quant);
    gotoxy(77,18);printf("R$ %.2f",book.preco);
    return;
}
/***************** Pesquisa se existe o codigo cadastrado no arquivo *********************************/
int pesquisa_livro(int NUM){
    int achou = 0;
    rewind(liv);
    while(!feof(liv) && achou != 1){
        fread(&book,sizeof(struct LIVRO),1,liv);
        if(NUM == book.cod)
            achou=1;
    }return(achou);
}

/**************************** Exclui o livro ***************************************************/

/**Cria uma arquivo auxilar para a exclusao,apos exclusao pega o estrutura de dados modificado e passa para o arquivo original novamente*/
int excluir_livro(int NUM){
    FILE *aux;//cria um ponteiro auxiliar
    fclose(liv);
    system("copy LIV.DAT DADOS.DAT");//copia os dados do arquivo que contem os usuario para um arquivo auxiliar
    gotoxy(32,20);limpaavisos();
    gotoxy(20,20);system("del LIV.DAT");//apaga o arquivo de usuarios
    limpaavisos();
    liv=fopen("LIV.DAT","wb+");
    aux=fopen("DADOS.DAT","rb+");
    rewind(aux);
    while(!feof(aux)){
        fread(&book,sizeof(struct LIVRO),1,aux);
        if (NUM!=book.cod)
            fwrite(&book,sizeof(struct LIVRO),1,liv);
    }fclose(aux);
    system("del DADOS.DAT");//apaga arquivo auxiliar
    centro(21,"Livro excluido. Pressione [ENTER] para prosseguir");
    fflush(stdin);
    while((tecla=getchar())!='\n')
        gotoxy(53,21);
    return(0);}
/***************** Inclui Livros *************************************************/

/** Inclui livros com codigo não existentes */
int incluir_livro(void){
    limpatela();cabecalho();
    centro(2,sistema);
    centro(3," Incluir Livro \n");printf("\n");
    centro(5," Digite os dados ");
    do{
        naosalvar:limpaavisos();
        centro(23,"Digite [0] para voltar ao menu");
        tela_cadastro_livro();
        gotoxy(77,10);fflush(stdin);scanf("%d",&num_liv);
        if (num_liv != 0){
            if (pesquisa_livro(num_liv)==1){
				exibedados_livro();
				if(book.excluido!=1){limpalinha(20);centro(20,"\aEste livro ja existe");}
				else {limpalinha(20);centro(20,"\aEste livro foi exluido");}
				centro(21,"Tecle [ENTER] para nova tentativa");
				fflush(stdin);while((tecla=getchar())!='\n')gotoxy(70,21);
				limpaavisos();
			}else{
				fseek(liv,(long)sizeof(struct LIVRO),2);
				gotoxy(77,11);
				fflush(stdin);fgets(book.titulo,50,stdin);
				gotoxy(77,12);
				fflush(stdin);fgets(book.autor,50,stdin);
				gotoxy(77,13);
				fflush(stdin);fgets(book.editora,30,stdin);
				gotoxy(77,14);
				fflush(stdin);fgets(book.edicao,10,stdin);
				gotoxy(77,15);
				fflush(stdin);fgets(book.tema,20,stdin);
				gotoxy(77,16);
				fflush(stdin);fgets(book.isbn,13,stdin);
				gotoxy(77,17);
				fflush(stdin);scanf("%d",&book.quant);
				gotoxy(77,18);
				fflush(stdin);scanf("%f",&book.preco);
				book.cod = num_liv;
				book.excluido =0;
				centro(21,"Deseja salvar este Livro [S/N]?");fflush(stdin);fgets(opt,2,stdin);
                        if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){goto naosalvar;}
                        else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        limpaavisos();fwrite(&book,sizeof(struct LIVRO),1,liv);centro(20,"Livro Salvo");}
                    else{
                    limpalinha(21);centro(21,"Digite [S ou N] | Pressione [ENTER] para continuar");
                    while((tecla=getchar())!='\n')gotoxy(53,23);}
			}
        }
    }
    while(num_liv!=0);
    return(0);
}
/**************************************************************************/

/**Listar livro */
void listar_livro(void){
    int i=5;
    int cesp=442,ini=442,fim=442,a=461;
    rewind(liv);
    limpatela();
    centro(1,"Lista de Livros");
    gotoxy(0,2);linhap(80,461,0);gotoxy(0,2);printf("%c",457);gotoxy(79,2);printf("%c",443);gotoxy(6,2);printf("%c",459);gotoxy(19,2);printf("%c",459);gotoxy(29,2);printf("%c",459);gotoxy(37,2);printf("%c",459);gotoxy(44,2);printf("%c",459);gotoxy(53,2);printf("%c",459);gotoxy(67,2);printf("%c",459);gotoxy(73,2);printf("%c",459);
    gotoxy(0,3);printf("%c COD %c",ini,cesp);gotoxy(7,3);printf("   TITULO   %c",cesp);gotoxy(20,3);printf("  AUTOR  %c",cesp);gotoxy(30,3);printf("EDITORA%c",cesp);gotoxy(38,3);printf("EDI%c%cO%c",CEDILHA,455,cesp);gotoxy(45,3);printf("  TEMA  %c",cesp);gotoxy(54,3);printf("     ISBN    %c",cesp);gotoxy(68,3);printf("QUANT%c",cesp);gotoxy(74,3);printf("PRE\x80O%c",fim);
    gotoxy(0,4);linhap(80,461,0);gotoxy(0,4);printf("%c",460);gotoxy(79,4);printf("%c",441);gotoxy(6,4);printf("%c",462);gotoxy(19,4);printf("%c",462);gotoxy(29,4);printf("%c",462);gotoxy(37,4);printf("%c",462);gotoxy(44,4);printf("%c",462);gotoxy(53,4);printf("%c",462);gotoxy(67,4);printf("%c",462);gotoxy(73,4);printf("%c",462);
    while(fread(&book,sizeof(struct LIVRO),1,liv)==1){//usuarios com valor 0 não existe, lista todos os usuario cadastrados
        if(book.cod==0)//teste logica para não exibir o codigo 0, codigo reservado para saida de telas
        limpalinha(i);
        else{
            gotoxy(0,i);printf("%c",cesp);gotoxy(1,i);printf("%d",book.cod);gotoxy(6,i);printf("%c",cesp);gotoxy(7,i);printf("%s",book.titulo);gotoxy(19,i);printf("%c",cesp);gotoxy(20,i);printf("%s",book.autor);gotoxy(29,i);printf("%c",cesp);gotoxy(30,i);printf("%s",book.editora);gotoxy(37,i);printf("%c",cesp);gotoxy(38,i);printf("%s",book.edicao);gotoxy(44,i);printf("%c",cesp);gotoxy(45,i);printf("%s",book.tema);gotoxy(53,i);printf("%c",cesp);gotoxy(54,i);printf("%s",book.isbn);gotoxy(67,i);printf("%c",cesp);gotoxy(68,i);printf("%d",book.quant);gotoxy(73,i);printf("%c",cesp);gotoxy(74,i);printf("%.2f",book.preco);gotoxy(79,i);printf("%c",fim);
            i++;
            }

}gotoxy(0,i);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",456,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,458,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,458,a,a,a,a,a,444);
centro(i+2,"Pressione [ENTER] para Voltar ao Menu Livros");fflush(stdin);while((tecla=getchar())!='\n')gotoxy(23,i+2);tela_livro();
}
/********************************************************************/

/** faz a pesquisa exibindo o livro*/
void pesquisar_livro(void){
    limpatela();cabecalho();
    centro(2,sistema);
    centro(3,"Livro\n\n");
    gotoxy(60,6);printf("Codigo: ");
    do{
        limpaavisos();
        centro(23,"Digite [0] para voltar ao menu de livro");
        tela_cadastro_livro();
        gotoxy(77,6);fflush(stdin);scanf("%d",&num_liv);limpaavisos();
        if (num_liv!=0){
            i=pesquisa_livro(num_liv);
            if(i==1 && book.excluido == 0){//??
                exibedados_livro();
                alterar:
                limpaavisos();
                if (escolha == 0){
                    limpalinha(21);centro(21,"Deseja editar este livro[S/N]?");fflush(stdin);fgets(opt,2,stdin);
                    if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                    else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        limpaavisos();cabecalho();centro(3,"Editar Livro");editar_livro();
                    }else{
						limpalinha(21);centro(21,"Digite S ou N!!! Pressione [ENTER] para continuar");
                    while((tecla=getchar())!='\n')gotoxy(70,21);goto alterar;}
				}else {
					limpalinha(21);centro(21,"Deseja excluir esse livro[S/N]?");fflush(stdin);fgets(opt,2,stdin);
					if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}//??
					else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
						limpaavisos();cabecalho();centro(3,"Excluir Livro");excluir_livro(num_liv);
					}else{
						limpalinha(21);centro(21,"\aDigite S ou N | Pressione [ENTER] para continuar");
						while((tecla=getchar())!='\n')gotoxy(70,21);goto alterar;}}
				limpalinha(21);centro(21,"Pressione [ENTER] para nova tentativa");
				fflush(stdin);while((tecla=getchar())!='\n');gotoxy(70,21);
			}else{
				if(book.excluido != 1){
				limpalinha(20);centro(20,"\aEste livro nao esta cadastrado!");}
				else{
					limpalinha(20);centro(20,"\aEste livro foi excluido!");
					exibedados_livro();}
				limpalinha(21);centro(21,"Pressione [ENTER] para nova tentativa");
				fflush(stdin);while((tecla=getchar())!='\n')gotoxy(37,21);
				limpaavisos();}
		}
    }while(num_liv!= 0);
    return(0);
}
/****************************************************************/

/**Editar livro */
int editar_livro(void){
    char op;
    int achou = 2;
    do{
        limpaavisos();centro(22,"[1]TITULO [2]AUTOR [3]EDITORA [4]EDI\x80\x1c7O [5]TEMA [6]ISBN [7]QUANTIDADE [8]PRE\x80O:");
        centro(23,"[9]CONFIRMA [0]CANCELA");
        fflush(stdin);op=getche();
        switch(op){
            case '1':
                gotoxy(77,11);printf("               ");gotoxy(77,11);
                fflush(stdin);fgets(book.titulo,50,stdin);break;
            case '2':
                gotoxy(77,12);printf("               ");gotoxy(77,12);
                fflush(stdin);fgets(book.autor,50,stdin);break;
            case '3':
                gotoxy(77,13);printf("               ");gotoxy(77,13);
                fflush(stdin);fgets(book.editora,50,stdin);break;
            case '4':
                gotoxy(77,14);printf("               ");gotoxy(77,14);
                fflush(stdin);fgets(book.edicao,10,stdin);break;
            case '5':
                gotoxy(77,15);printf("               ");gotoxy(77,15);
                fflush(stdin);fgets(book.tema,20,stdin);break;
            case '6':
                gotoxy(77,16);printf("             ");gotoxy(77,16);
                fflush(stdin);fgets(book.isbn,13,stdin);break;
            case '7':
                gotoxy(77,17);printf("               ");gotoxy(77,17);
                fflush(stdin);scanf("%d",&book.quant);break;
            case '8':
                gotoxy(77,18);printf("               ");gotoxy(77,18);
                fflush(stdin);scanf("%f",&book.preco);break;
            case '9':
                Confirma:
                    limpaavisos();centro(21,"Confirma a edi\x87\xc6o do livro[S/N]?");fflush(stdin);fgets(opt,2,stdin);
                    if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}//??
                    else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        achou=0;}
                    else{
                        limpalinha(21);centro(21,"\aDigite S ou N | Pressione [ENTER] para continuar");
                        while((tecla=getchar())!='\n')gotoxy(79,21);goto Confirma;}break;
            case '0':
                Cancela:
				limpalinha(21);centro(21,"Abandonar edi\x87\xc6o do livro? [S/N]");fflush(stdin);fgets(opt,2,stdin);
				if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                    else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        achou=1;
                    }else{
                        limpalinha(21);centro(21,"\aDigite S ou N | Pressione [ENTER] para continuar");
                        while((tecla=getchar())!='\n')gotoxy(53,21);goto Cancela;
                    }break;}
        limpaavisos();
    }while(achou!=0&&achou!=1);
		if(achou==0){
			fseek(liv,-(long)sizeof(struct LIVRO),1);
			fwrite(&book,sizeof(struct LIVRO),1,liv);
			centro(21,"\aAltera\x87\xc6o bem sucedida | Pressione [ENTER] para prosseguir");
		}else{
			limpalinha(21);centro(21,"\aSem Altera\x87\xc6o | Pressione [ENTER] para prosseguir");}
		fflush(stdin);while((tecla=getchar())!='\n')gotoxy(33,23);
			limpaavisos();
			return(0);
}

/******************** ROTINAS E FUNÇOES EMPRESTIMOS ***************************************************/
void tela_e(void){
    /*Verifica a existencia do arquivo, se não existir cria*/
        char op1;
        system("title GESTÃO DE BIBLIOTECA");
        if ((emp=fopen("EMP.DAT","rb+"))==NULL){
            emp=fopen("EMP.DAT","wb+");
            fwrite(&e,sizeof(struct EMPRESTIMO),1,emp);}
        do{
            limpatela();cabecalho();//desenhatela();
            centro(2,sistema);
            centro(3,"Menu Emprestimo\n");
            gotoxy(60,7);linhaq(37,475);
            gotoxy(60,8);printf("\xdb                                   \xdb");
            gotoxy(60,9);printf("\xdb.....[1]-> Emprestar...............\xdb");
            gotoxy(60,10);printf("\xdb                                   \xdb");
            gotoxy(60,11);printf("\xdb.....[2]-> Pesquisar...............\xdb");
            gotoxy(60,12);printf("\xdb                                   \xdb");
            gotoxy(60,13);printf("\xdb.....[3]-> Listar..................\xdb");
            gotoxy(60,14);printf("\xdb                                   \xdb");
            gotoxy(60,15);printf("\xdb.....[4]-> Excluir.................\xdb");
            gotoxy(60,16);printf("\xdb                                   \xdb");
            gotoxy(60,17);printf("\xdb.....[5]-> Devolver................\xdb");
            gotoxy(60,18);printf("\xdb                                   \xdb");
            gotoxy(60,19);printf("\xdb.....[0]-> Voltar..................\xdb");
            gotoxy(60,20);printf("\xdb                                   \xdb");
            gotoxy(60,21);printf("\xdb..........Escolha uma op%c%co:[   ]..\xdb",cedilha,tioa);
            gotoxy(60,22);printf("\xdb                                   \xdb");
            gotoxy(60,23);linhaq(37,475);
            gotoxy(91,21);op1=getche();fflush(stdin);
            switch(op1){
        case '1':
            incluir_e();break;
        case '2':
            escolha=0;pesquisar_e();break;
        case '3':
            listar_emprestados();break;
        case '4':
            escolha=1;pesquisar_e();break;
        case '5':
            escolha=0;devolver_e();break;

            }
        }while(op1!='0');
        fclose(emp);limpatela();tela_principal();
}
/*********************************************************************************************************/
   /*tela para menu do funcionario*/
    void tela_cadastro_e(void){
        limpalinha(10);
        limpalinha(11);
        limpalinha(12);
        limpalinha(13);
        limpalinha(14);
        limpalinha(15);
        gotoxy(60,10);printf("Codigo do Emprestimo..........:     ");
        gotoxy(60,11);printf("Codigo do Leitor..............:     ");
        gotoxy(60,12);printf("Codigo do Funcionario.........:     ");
        gotoxy(60,13);printf("Codigo do Livro...............:     ");
        gotoxy(60,14);printf("Data de Emprestimo............: __/__/____ ");
        gotoxy(60,15);printf("Data prevista de devolu%c%co....: __/__/____ ",cedilha,tioa);
        return;}
/*********************************************************************************************************/
   /*tela para menu do funcionario*/
    void tela_cadastro_e2(void){
        limpalinha(8);
        limpalinha(10);
        limpalinha(11);
        limpalinha(12);
        limpalinha(13);
        limpalinha(14);
        limpalinha(15);
        gotoxy(60,10);printf("Codigo do Emprestimo..........:            ");
        gotoxy(60,11);printf("Leitor........................:            ");
        gotoxy(60,12);printf("Funcionario...................:            ");
        gotoxy(60,13);printf("Livro.........................:            ");
        gotoxy(60,14);printf("Data de Emprestimo............:[__/__/____]");
        gotoxy(60,15);printf("Data prevista de devolu%c%co....:[__/__/____]",cedilha,tioa);
        return;}
/********************************************************************************************************/
    /*Mostra os dados quando há pesquisa ou tentativa de cadastro do funcionario*/
    void exibedados_e(void){
        tela_cadastro_e2();
        gotoxy(91,10);printf("                 ");gotoxy(91,10);printf(" %d ",e.cod);
        user=fopen("USER.DAT","r");pesquisa(e.usuario);
        gotoxy(91,11);printf("                 ");gotoxy(91,11);printf(" %s",c.nome);
        func=fopen("FUNC.DAT","r");pesquisa_f(e.func);
        gotoxy(91,12);printf("                 ");gotoxy(91,12);printf(" %s",f.nome);
        liv=fopen("LIV.DAT","r");pesquisa_livro(e.livro);
        gotoxy(91,13);printf("                 ");gotoxy(91,13);printf(" %s",book.titulo);
        gotoxy(91,14);printf("                 ");gotoxy(91,14);printf(" %d/%d/%d ",e.empdia,e.empmes,e.empano);
        gotoxy(91,15);printf("                 ");gotoxy(91,15);printf(" %02d/%02d/%4d ",e.devdia,e.devmes,e.devano);
        return;
    }
/**********************************************************************************************************/
/*Pesquisa se existe algum emprestimo cadastrado com o codigo*/
int pesquisa_e(int NUM){
    int achou=0;
    rewind(emp);
    while(!feof(emp)&&achou!=1){
        fread(&e,sizeof(struct EMPRESTIMO),1,emp);
        if(NUM == e.cod)
            achou=1;
    }return(achou);}

int excluir_e(int NUM){
    FILE *aux;//cria um ponteiro auxiliar
    fclose(emp);
    system("copy EMP.DAT DADOS.DAT");//copia os dados do arquivo que contem os usuario para um arquivo auxiliar
    gotoxy(32,20);limpaavisos();
    system("del EMP.DAT");//apaga o arquivo de usuarios
    emp=fopen("EMP.DAT","wb+");//abre novo arquivo
    aux=fopen("DADOS.DAT","rb+");//abre novo arquio auxiliar
    rewind(aux);
    while(!feof(aux)){
        fread(&e,sizeof(struct EMPRESTIMO),1,aux);
        if (NUM!=e.cod)//codigos cadastrados diferente do argumento sao copiados
            fwrite(&e,sizeof(struct EMPRESTIMO),1,emp);}
            fclose(aux);
    system("del DADOS.DAT");//apaga arquivo auxiliar
    centro(21,"Leitor excluido. Pressione [ENTER] para prosseguir");
    fflush(stdin);while((tecla=getchar())!='\n')gotoxy(53,21);
    return(0);
}
devolver(int NUM){
    char datastr[9];
    _strdate(datastr);//pega a data atual
            struct DATA data;
            recebeData(datastr,&data);
            e.diadevolvido=data.dia;
            e.mesdevolvido=data.mes;
            e.anodevolvido=data.ano+2000;
    fclose(user);
    user=fopen("USER.DAT","rb+");
    pesquisa(e.usuario);
    c.status=0;
    fseek(user,-(long)sizeof(struct CLIENTE),1);
    fwrite(&c,sizeof(struct CLIENTE),1,user);
    fclose(user);
    fclose(liv);
    liv=fopen("LIV.DAT","rb+");
    pesquisa(e.livro);
    book.quant=book.quant+1;
    fseek(liv,-(long)sizeof(struct LIVRO),1);
    fwrite(&book,sizeof(struct LIVRO),1,liv);
    fclose(liv);
    e.devolvido=1;
    fseek(emp,-(long)sizeof(struct EMPRESTIMO),1);
    fwrite(&e,sizeof(struct EMPRESTIMO),1,emp);
    centro(20,"Emprestimo devolvido. Pressione [ENTER] para prosseguir.");}
/*******************************************************************************************************/
devolver_e(void){
    limpatela();
    linha();
    centro(2,sistema);
    centro(3,"Emprestimo\n\n");
    linha();
    limpalinha(6);
    gotoxy(60,6);printf("Codigo:");
    do{
        limpaavisos();
        centro(23,"Digite [0] para voltar ao menu de EMPRESTIMOS");
        tela_cadastro_e();
        gotoxy(77,6);fflush(stdin);scanf("%d",&num_e);
        if (num_e!=0){
            y=pesquisa_e(num_e);
            if(y==1&&e.devolvido==0){
                exibedados_e();
                alterar:
                    limpaavisos();
                    if (escolha==0){
                        limpaavisos();
                        centro(21,"Deseja devolver este emprestimo [S/N]?");fflush(stdin);fgets(opt,2,stdin);
                        if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                        else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                            devolver(num_e);
                        }
                    else{
                    limpaavisos();
                    centro(21,"Digite S ou N!!! Pressione [ENTER] para continuar");
                    fflush(stdin);while((tecla=getchar())!='\n')gotoxy(70,21);
                        goto alterar;
                    }
            }
        limpalinha(21);
        centro(21,"Pressione [ENTER] para nova tentativa");
        fflush(stdin);while((tecla=getchar())!='\n');gotoxy(33,21);
        limpalinha(21);

    }
    else{
        limpaavisos();
        if(e.devolvido==1){
        limpaavisos();
        centro(20,"\aEste emprestimo foi devolvido");
        exibedados_e();}
        else{
            limpaavisos();
            centro(20,"\aEste emprestimo foi excluido!");}
        limpalinha(21);
        centro(21,"Pressione [ENTER] para nova tentativa");
        fflush(stdin);while((tecla=getchar())!='\n')gotoxy(37,21);
        limpaavisos();
    }
    }
    }while(num_e!=0);
    return(0);
}
/****************************************************************************************************/
/* Inclui novos emprestimos */
int incluir_e(void){
    char datastr[9];
    int auxdia,auxmes,auxano,ult,devoldia,devolmes,devolano;
    limpatela();
    linha();
    centro(2,sistema);
    centro(3,"Emprestimo de Livro\n");
    printf("\n");
    linha();
    centro(5," Digite os dados ");
    do{
        naosalvar:limpaavisos();centro(23,"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Digite [0] para cancelar \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
        voltar:
        tela_cadastro_e();
        gotoxy(92,10);fflush(stdin);scanf("%d",&num_e);
        if (num_e!=0){
                centro(18,"                           ");
                if (pesquisa_e(num_e)==1)
                    {
            limpalinha(20);limpalinha(21);
            tela_cadastro_e2();
            exibedados_e();
            if(e.devolvido!=1&&e.excluido!=1)centro(20,"\aEste emprestimo ja existe");
            else centro(20,"\aEste emprestimo foi excluido");
            centro(21,"Tecle [ENTER] para nova tentativa");
            fflush(stdin);while((tecla=getchar())!='\n')gotoxy(70,22);
            limpalinha(20);limpalinha(21);
        }
        else{
            usuario://pedi novamente o codigo do usuario caso o codigo nao esteja cadastrado
            gotoxy(91,11);printf("     ");
            gotoxy(92,11);fflush(stdin);scanf("%d",&cod_usuario);
            limpalinha(20);
            if(cod_usuario!=0){
            fclose(user);
            user=fopen("USER.DAT","rb+");
            if(pesquisa(cod_usuario)==1){//pesquisa se existe algum usuario com o codigo cadastrado
                if(c.status!=1){
                limpalinha(11);gotoxy(60,11);printf("Usuario.......................:     ");
                gotoxy(91,11);printf("%s",c.nome);}//imprimi o nome do usuario}
                else{   limpalinha(11);gotoxy(60,11);printf("Usuario.......................:     ");
                        gotoxy(91,11);printf(" %s",c.nome);//imprimi o nome do usuario
                        centro(20,"\aPermitido apenas um emprestimo por vez!");Sleep(1000);goto usuario;}}
            else{centro(20,"\aUsuario nao cadastrado");goto usuario;}//se a pesquisa retornar 0 volta ao inicio do else
            funcionario:
            gotoxy(91,12);printf("     ");
            gotoxy(92,12);
            fflush(stdin);scanf("%d",&cod_func);
            limpalinha(20);
            if(cod_func!=0){
            fclose(func);
            func=fopen("FUNC.DAT","r");
            if(pesquisa_f(cod_func)==1){                                           //
                limpalinha(12);gotoxy(60,12);printf("Funcionario...................:     ");
                gotoxy(91,12);printf("%s",f.nome);
                centro(18,"                            ");}
                else{centro(20,"\aFuncionario nao cadastrado");goto funcionario;}//se a pesquisa retornar 0 volta ao inicio do else
            livroinvalido:livroinvalido2:
            gotoxy(91,13);printf("     ");
            gotoxy(92,13);fflush(stdin);scanf("%d",&cod_livro);
            limpalinha(20);
            if(cod_livro!=0){
            fclose(liv);
            liv=fopen("LIV.DAT","rb+");
            if(pesquisa_livro(cod_livro)==1){
                    if(book.quant>0){
                limpalinha(13);gotoxy(60,13);printf("Livro.........................:     ");
                gotoxy(91,13);printf("%s",book.titulo);
                centro(18,"                            ");}
                else {limpalinha(13);gotoxy(60,13);printf("Livro.........................:     ");
                gotoxy(91,13);printf("         %s",book.titulo);
                centro(20,"\aLivro Indiponivel");goto livroinvalido;}}
            else{limpalinha(13);gotoxy(60,13);printf("Livro.........................:     ");
                    centro(20,"\aLivro nao cadastrado");goto livroinvalido2;}//se a pesquisa retornar 0 volta ao goto
            datainvalida:
            limpaavisos();
            _strdate(datastr);//pega a data atual
            struct DATA data;
            recebeData(datastr,&data);
            auxdia=data.dia;
            auxmes=data.mes;
            auxano=data.ano+2000;
            gotoxy(92,14);printf("%02d/%02d/%d",auxdia,auxmes,auxano);
            //datainvalida2:
            centro(18,"                       ");
            devoldia=somadatadia(auxdia,auxmes,auxano,10);
            devolmes=somadatames(auxdia,auxmes,auxano,10);
            devolano=somadataano(auxdia,auxmes,auxano,10);//somadataano(auxdia,auxmes,auxano);
            gotoxy(92,15);printf("%02d/%02d/%04d",devoldia,devolmes,devolano);
            gotoxy(92,15);
            /*fflush(stdin);scanf("%d",&dia_d);
            gotoxy(55,15);
            fflush(stdin);scanf("%d",&mes_d);
            gotoxy(58,15);
            fflush(stdin);scanf("%d",&ano_d);
            if(valida_data(dia_d,mes_d,ano_d)==0){
                centro(18,"\aData Invalida");
                goto datainvalida2;*/
            centro(21,"Deseja salvar este Emprestimo [S/N]?");fflush(stdin);fgets(opt,2,stdin);
                        if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){goto naosalvar;}
                        else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        limpaavisos();
            pesquisa(cod_usuario);
            c.status=1;
            fseek(user,-(long)sizeof(struct CLIENTE),1);
            fwrite(&c,sizeof(struct CLIENTE),1,user);fclose(user);
            pesquisa_livro(cod_livro);
            book.quant=book.quant-1;
            fseek(liv,-(long)sizeof(struct LIVRO),1);
            fwrite(&book,sizeof(struct LIVRO),1,liv);fclose(liv);
            fseek(emp,(long)sizeof(struct EMPRESTIMO),2);
            e.cod=num_e;
            e.usuario=cod_usuario;
            e.func=cod_func;
            e.livro=cod_livro;
            e.empdia=auxdia;
            e.empmes=auxmes;
            e.empano=auxano;
            e.devdia=devoldia;
            e.devmes=devolmes;
            e.devano=devolano;
            e.devolvido=0;
            e.excluido=0;
            fwrite(&e,sizeof(struct EMPRESTIMO),1,emp);
            centro(21,"Tecle <ENTER> para salvar!");
            fflush(stdin);while((tecla=getchar())!='\n')gotoxy(33,21);
            fclose(func);}
            else{
                    limpalinha(21);centro(21,"Digite [S ou N] | Pressione [ENTER] para continuar");
                    while((tecla=getchar())!='\n')gotoxy(53,23);}
            }goto voltar;}goto voltar;}else{centro(20,"   Codigo nao permitido   ");}
            }}
            }while(num_e!=0);
    return(0);
}
/*************************************************************************************/
void listar_emprestados(void){
    int i=5;
    int cesp=442,ini=442,fim=442,a=461;
    rewind(emp);
    limpatela();
    centro(1,"Lista de Emprestimos");
    gotoxy(0,2);linhap(80,461,0);gotoxy(0,2);printf("%c",457);gotoxy(4,2);printf("%c",459);gotoxy(22,2);printf("%c",459);gotoxy(38,2);printf("%c",459);gotoxy(52,2);printf("%c",459);gotoxy(66,2);printf("%c",459);gotoxy(79,2);printf("%c",187);
    gotoxy(0,3);printf("%cCOD%c",ini,cesp);gotoxy(5,3);printf("      LEITOR     %c",cesp);gotoxy(23,3);printf("  FUNCIONARIO  %c",cesp);gotoxy(39,3);printf("   LIVRO     %c",cesp);gotoxy(53,3);printf("DT EMPRESTIMO%c",cesp);gotoxy(67,3);printf("DT DEVOLU\x80\x1c7O\x1ba");
    gotoxy(0,4);linhap(80,461,0);gotoxy(0,4);printf("%c",460);gotoxy(4,4);printf("%c",462);gotoxy(22,4);printf("%c",462);gotoxy(38,4);printf("%c",462);gotoxy(52,4);printf("%c",462);gotoxy(66,4);printf("%c",462);gotoxy(79,4);printf("%c",441);
    while(fread(&e,sizeof(struct EMPRESTIMO),1,emp)==1){//usuarios com valor 0 não existe, lista todos os usuario cadastrados
        if(e.cod==0)//teste logica para não exibir o codigo 0, codigo reservado para saida de telas
        limpalinha(i);
        else{
            gotoxy(0,i);printf("%c",cesp);gotoxy(1,i);printf("%d",e.cod);
            user=fopen("USER.DAT","r");
            pesquisa(e.usuario);
            gotoxy(4,i);printf("%c",cesp);gotoxy(5,i);printf("%s",c.nome);
            func=fopen("FUNC.DAT","r");
            pesquisa_f(e.func);
            gotoxy(22,i);printf("%c",cesp);gotoxy(23,i);printf("%s",f.nome);
            liv=fopen("LIV.DAT","r");
            pesquisa_livro(e.livro);
            gotoxy(38,i);printf("%c",cesp);gotoxy(39,i);printf("%s",book.titulo);
            gotoxy(52,i);printf("%c",cesp);gotoxy(53,i);printf("  %02d/%02d/%04d",e.empdia,e.empmes,e.empano);
            if(e.devolvido!=1){gotoxy(66,i);printf("%c",cesp);gotoxy(67,i);printf("NAO DEVOLVIDO");gotoxy(79,i);printf("%c",fim);}
            else{gotoxy(66,i);printf("%c",cesp);gotoxy(67,i);printf("%d/%d/%d",e.diadevolvido,e.mesdevolvido,e.anodevolvido);gotoxy(79,i);printf("%c",fim);}
            i++;
            }

}gotoxy(0,i);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",456,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,a,458,a,a,a,a,a,a,a,a,a,a,a,a,444);
centro(i+2,"Pressione [ENTER] para Voltar ao Menu EMPRESTIMO");fflush(stdin);while((tecla=getchar())!='\n')gotoxy(23,i+2);tela_e();
}
/**************************************************************************************************************/
/* Pesquisa emprestimo por codigo*/
pesquisar_e(void){
    limpatela();cabecalho();
    centro(2,sistema);
    centro(3,"Emprestimo\n\n");
    limpalinha(6);
    gotoxy(60,6);printf("Codigo:");
    do{
        limpaavisos();
        centro(23,"Digite [0] para voltar ao menu de EMPRESTIMOS");
        tela_cadastro_e();
        gotoxy(77,6);fflush(stdin);scanf("%d",&num_e);
        if (num_e!=0){
            y=pesquisa_e(num_e);
            if(y==1&&e.devolvido==0){
                exibedados_e();
                alterar:
                limpaavisos();
                if (escolha == 0){
                    limpalinha(21);centro(21,"Deseja renovar este emprestimo [S/N]?");fflush(stdin);fgets(opt,2,stdin);
                    if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}
                    else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
                        limpaavisos();cabecalho();centro(3,"Renovar Emprestimo");renovar_e(num_e);
                    }else{
						limpalinha(21);centro(21,"Digite S ou N!!! Pressione [ENTER] para continuar");
                    while((tecla=getchar())!='\n')gotoxy(70,21);goto alterar;}
				}else {
					limpalinha(21);centro(21,"Deseja excluir este emprestimo[S/N]?");fflush(stdin);fgets(opt,2,stdin);
					if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){}//??
					else if(strcmp(opt,"s")==0||strcmp(opt,"S")==0){
						limpaavisos();cabecalho();centro(3,"Excluir emprestimo");excluir_e(num_e);
					}else{
						limpalinha(21);centro(21,"\aDigite S ou N | Pressione [ENTER] para continuar");
						while((tecla=getchar())!='\n')gotoxy(70,21);goto alterar;}}
				limpalinha(21);centro(21,"Pressione [ENTER] para nova tentativa");
				fflush(stdin);while((tecla=getchar())!='\n');gotoxy(70,21);
			}else{
				if(e.devolvido != 1){
				limpalinha(20);centro(20,"\aEste livro nao esta cadastrado!");}
				else{
					limpalinha(20);centro(20,"\aEste livro foi excluido!");
					exibedados_livro();}
				limpalinha(21);centro(21,"Pressione [ENTER] para nova tentativa");
				fflush(stdin);while((tecla=getchar())!='\n')gotoxy(37,21);
				limpaavisos();}
    }}while(num_e!=0);
    return(0);
}
/**********************************************************************************************************************/
/*Renova emprestimo*/
int renovar_e(int NUM){
    char datastr[9];
    int auxdia,auxmes,auxano,ult,devoldia,devolmes,devolano;
    _strdate(datastr);//pega a data atual
            struct DATA data;
            recebeData(datastr,&data);
            auxdia=data.dia;
            auxmes=data.mes;
            auxano=data.ano+2000;
            //datainvalida2:
            devoldia=somadatadia(auxdia,auxmes,auxano,10);
            devolmes=somadatames(auxdia,auxmes,auxano,10);
            devolano=somadataano(auxdia,auxmes,auxano,10);//somadataano(auxdia,auxmes,auxano);
            gotoxy(92,15);printf("%02d/%02d/%04d",devoldia,devolmes,devolano);
            gotoxy(92,15);
            e.devdia=devoldia;
            e.devmes=devolmes;
            e.devano=devolano;
            fseek(emp,-(long)sizeof(struct EMPRESTIMO),1);
            fwrite(&e,sizeof(struct EMPRESTIMO),1,emp);
            centro(20,"Emprestimo Renovado! Pressione [ENTER] para prosseguir");
}
/*******************************************************************************************************/
int autorizado ( const char *id, const char *pss ){// "const char" é uma constante em que o seu valor não pode ser mudado, ao contrário de "char" em que o seu valor pode ser modificado.

  int i;
  for ( i = 0; i < length ( conta ); i++ ){
    if ( stricmp ( id, conta[i].id ) == 0 &&
         strcmp ( pss, conta[i].password ) ==0 )//"strcm" - compara as variáveis id e password e de seguida devolve.
    {
      return 1;
    }}
  return 0;}
void get_password ( char *pss, int size ){
  int i = 0;
  int ch;
  while ( i < size - 1 && ( ch = getch() ) != '\r' ){
    if ( ch == '\b' ) {
      if ( i != 0 ) {
        printf ( "\b%c\b", ' ' );
        --i;}}
    else {  putchar ( '*' );
          //faz com que a password dos utilizadores aparece com *
      pss[i++] = (char)ch;}}
  pss[i] = '\0';}
int log(){
    char id[FIELD_SIZE];
    char pss[FIELD_SIZE];
    int i=0,j=6;
    system("title LOGIN");
    limpatela();cabecalho();
    do{
        centro(3,"LOGIN\n");
        gotoxy(67,24);linhaq(24,475);
        centro(25,"\xdb                      \xdb");
        centro(26,"\xdb                      \xdb");
        centro(27,"\xdb                      \xdb");
        centro(28,"\xdb                      \xdb");
        centro(29,"\xdb                      \xdb");
        centro(30,"\xdb                      \xdb");
        centro(31,"\xdb                      \xdb");
        gotoxy(67,32);linhaq(24,475);
        gotoxy(69,27);printf ( "Usuario...:" );
        gotoxy(69,29);printf ( "Senha.....:" );
        fflush (stdout);
        gotoxy(81,27);
        if (fgets(id,sizeof id,stdin)!=NULL){
        char *newline=strchr( id,'\n');
        if ( newline != NULL )
        *newline = '\0';
        fflush ( stdout );
        gotoxy(81,29);get_password ( pss, sizeof pss );
        if ( autorizado ( id, pss ) )
      {tela_principal();i=8;}
        else{
          gotoxy(59,34);printf("                                        ");
          gotoxy(59,35);printf("                                        ");
          gotoxy(59,36);printf("                                        ");
          gotoxy(59,37);printf("                                        ");
          gotoxy(59,38);printf("                                        ");
          gotoxy(59,35);printf("    \xdb\xdb Voce tem mais %d tentativas \xdb\xdb",j-1);
          gotoxy(66,36);printf("   \a\xdb\xdb Login Invalido \xdb\xdb");
          centro(37,"  Pressione [ENTER] para nova tentativa ");
          fflush(stdin);while((tecla=getchar())!='\n');gotoxy(31,21);
          centro(37,"                                        ");}
            i++;j--;}
    }while(i<6);
    limpatela();
    if(i<7){centro(3,"LOGIN\n");
    gotoxy(60,30);printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    gotoxy(60,31);printf("\a\xdb\xdb\xdb\xdb\xdb Tentativas Excedidas \xdb\xdb\xdb\xdb\xdb");
    gotoxy(60,32);printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");Sleep(3000);}
    else{gotoxy(60,30);printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    gotoxy(60,31);printf("\a\xdb\xdb\xdb\xdb\xdb     Ate a Proxima    \xdb\xdb\xdb\xdb\xdb");
    gotoxy(60,32);printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");Sleep(3000);}}

/************************************************************************************/
    int main(void)
    {
        system("MODE con cols=170 lines=60");
      /*  keybd_event ( VK_MENU, 0x36, 0, 0 );
        keybd_event ( VK_RETURN, 0x1C, 0, 0 );
        keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
        keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );*/
        cor();//define a cor de fundo branca e as letras preta
        log();}

   /*******************************************************************************************/
