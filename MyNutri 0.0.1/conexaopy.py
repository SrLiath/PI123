
import psycopg2
# Conecta no banco
con = psycopg2.connect(
    host="ec2-34-203-182-65.compute-1.amazonaws.com",
    database="dp89gpr843f41",
    user="chvtvrlfasbers",
    password="senha oculta",
    port="5432")

 # Função para criar tabela no banco
def criar_db(sql):
  cur = con.cursor()
  cur.execute(sql)
  con.commit()
  con.close()
  
# Função para ler arquivo tabela
def ler_db(sql):
    cur = con.cursor() # Cria um cursor com os dados de conexão (mesmo que o cur = con.cursor)
    cur.execute(sql)  # Executa o comando sql
    data = cur.fetchall() # Pega todos os dados da tabela para sair
    print(data)
