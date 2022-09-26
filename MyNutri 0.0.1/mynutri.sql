create table usernutri(
login Varchar (20) PRIMARY KEY,
senha Varchar(100) NOT NULL,
email varchar(100) NOT NULL,
inscricao varchar(15) NOT NULL,
tipocrn int);
create table taco (num int PRIMARY KEY,
descricaoalimen varchar(200),
umidade float(5),
energiakcal float (10),
proteinag float(5),
lipideosg float(5),
colesterolmg varchar(7),
carboidratog float(5),
fibrag float(5),
cinzag float(5),
calciomg float(5),
magnesiomg float(5));
