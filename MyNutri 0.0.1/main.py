import os
import time
import psycopg2
from ast import Try
from ctypes.wintypes import INT

#logo do mynutri
print("\n  ███╗   ███╗██╗   ██╗███╗   ██╗██╗   ██╗████████╗██████╗ ██╗\n  ████╗ ████║╚██╗ ██╔╝████╗  ██║██║   ██║╚══██╔══╝██╔══██╗██║\n  ██╔████╔██║ ╚████╔╝ ██╔██╗ ██║██║   ██║   ██║   ██████╔╝██║\n  ██║╚██╔╝██║  ╚██╔╝  ██║╚██╗██║██║   ██║   ██║   ██╔══██╗██║\n  ██║ ╚═╝ ██║   ██║   ██║ ╚████║╚██████╔╝   ██║   ██║  ██║██║\n  ╚═╝     ╚═╝   ╚═╝   ╚═╝  ╚═══╝ ╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝\n")
#barra de progresso
def progress_bar(done):
    print("\rCarregando: [{0:50s}] {1:.001f}%".format('#' * int(done * 50), done * 100),end='')

def test():
    for n in range(101):
        progress_bar(n/100)
        time.sleep(0.05)


test()

os.system("cls || clear")
# Conecta no banco
con = psycopg2.connect(
    host="ec2-34-203-182-65.compute-1.amazonaws.com",
    database="dp89gpr843f41",
    user="chvtvrlfasbers",
    password="6c59a2e731cb30283172b558207d810c896dba007067dd2ab08477add1ab82czaiac",
    port="5432")


cur = con.cursor()
query = (
    "INSERT INTO taco (num, descricaoalimen, umidade, energiakcal, proteinag, lipideosg, colesterolmg, carboidratog, fibrag, cinzag,  calciomg, magnesiomg) values (1, 'pao', 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.2, 22.2), (3, 'manteiga', 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.2, 22.2);")

cur.execute(query)




# iniciação do programa
print("\nOla usuario, Seja Bem Vindo\n\n")
nome = input("Informe seu nome: ")
alogin = 1
while (alogin == 1):
    try:
        codigo = int(input("\nInforme o seu codigo de acesso: "))
        if not 1000000 <= codigo <= 9999999:
            raise ValueError("\nInfelizmente nao localizamos seu codigo, verifique seu cadastro na plataforma\nou verifique atraves do email Suporte@MyNutri.com.br")
    except ValueError as e:
        print("\nDigite seu Codigo de plataforma")
    else:
        sql = ("select cod from usernutri where cod = " + str(codigo))
        cur = con.cursor()
        cur.execute(sql)
        data = cur.fetchone()
        print(data)
        try:
            if (data[0] != codigo):
                alogin = 1
            else:
                alogin = 0
        except:
            alogin = 1
        os.system("cls || clear")
print("\n----------------------------------------------------------------------\n");
print("Seja bem vindo " + nome + "\nNosso gerenciador irá verificar suas consultas pré marcadas na região");
print("\n^+---------------------------------------------^+");
print("\n1 - Listar as chamados de pacientes\n");
print("\n2 - criação de dieta particular\n");
print("\n3 - Verificação da TACO\n");
print("\n^+---------------------------------------------^+");
loopmenu = 0
while (loopmenu == 0):
    menu = input("\nEscolha sua opção: ")
    if (menu == "1"):
        #clientes  = open('clientes.txt','r')
        #print (clientes.read)
        input ("aperte qualquer tecla para voltar")
    elif (menu == "2"):
        input("aperte qualquer tecla para voltar")
    elif (menu == "3"):
        cur = con.cursor()
        cur.execute("SELECT * FROM taco;")
        res = cur.fetchall()

        print("-------------------------------------------------")
        print(" Cod Descrição Umidade(%) Energia(kcal) Proteína(g) Lipídeos(g) Colesterol(mg) Carboidrato(g) Fibra Alimentar(g) Cinzas(g) Cálcio(mg) Magnésio(mg)")
        for lin in range(len(res)):
            for col in range(0,12):
                print("  " + str(str(res[lin][col])) + "  ", end ="")
            print()
        input ("aperte qualquer tecla para voltar")
    else:
            print("\nopção invalida")
