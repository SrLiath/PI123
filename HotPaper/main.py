import os

print ("╔╗░╔╗░░░╔╗╔═══╗░░░░░░░░░░░\n║║░║║░░╔╝╚╣╔═╗║░░░░░░░░░░░\n║╚═╝╠══╬╗╔╣╚═╝╠══╦══╦══╦═╗\n║╔═╗║╔╗║║║║╔══╣╔╗║╔╗║║═╣╔╝\n║║░║║╚╝║║╚╣║░░║╔╗║╚╝║║═╣║░\n╚╝░╚╩══╝╚═╩╝░░╚╝╚╣╔═╩══╩╝░\n░░░░░░░░░░░░░░░░░║║░░░░░░░\n░░░░░░░░░░░░░░░░░╚╝░░░░░░░")
import time

def progress_bar(done):
    print("\rProgress: [{0:50s}] {1:.001f}%".format('#' * int(done * 50), done * 100),end='')

def test():
    for n in range(101):
        progress_bar(n/100)
        time.sleep(0.02)


test()
a = 1
while (a==1):
    login = input("\nOlá Usuario, insira seu Login a seguir: ")
    #Linha 1: Usuario
    check = os.path.exists("Config.baianinho"+login)
    if (check == True):
        loss = open("Config.baianinho"+login, "r")
        content = loss.readlines()
        wordpass = content[1]
        passa = input("\nColoque a sua senha:")
        while (passa != wordpass):
            print("\nSenha incorreta")
            passa=input("\nColoque a sua senha:")
        loss.close()
        a=0
    else:
        vg=1
        a=0
        while (vg == 1):
            choice = input("\nVocê não possui cadastro, gostaria de cria um novo? \nDigite 1-S(Sim) ou 2-N(Não):\n")
            if (choice == "1"):
                ab = 1
                while (ab == 1):
                    criasenha = input("\nDigite sua senha: ")
                    criasenhaa = input("\nRepita sua senha: ")
                    if (criasenha != criasenhaa):
                        print("\nsenha errada, repita")
                    else:
                        loss = open("Config.baianinho" + login, "a+")
                        loss.write(login)
                        loss.close()
                        criapass = open("Config.baianinho" + login, "a+")
                        criapass.write("\n" + criasenha)
                        criapass.close()
                        test = 0
                        vg = 0
                        ab = 0
                        a = 1
            elif (choice == "2"):
                print ("Reiniciando...\n")
                test()
                vg = 0
                ab = 0
                a = 1
