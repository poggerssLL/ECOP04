from classes import Aluno
from disciplina import Disciplina
disciplinas_disponiveis = []

disc = Disciplina("POO", "Alyson", 64, "LEC1")
disciplinas_disponiveis.append(disc)

disc = Disciplina("Calculo", "EULER", 32, "I2118")
disciplinas_disponiveis.append(disc) 

aluno = Aluno("2024004143", "Erick", "ECA",["POO"], disciplinas_disponiveis)
aluno2 = Aluno("2024001234", "JUAO", "ECA",["POO"], disciplinas_disponiveis)

if aluno.insere_disciplina("Calculo",disciplinas_disponiveis):
    print("Aluno matriculado")
else:
    print("Aluno nao matriculado")


##print(aluno.disciplinas)
##aluno.remove_disciplina("Objeto fodase")
for x in range(len(aluno.disciplinas)):
    print(aluno.disciplinas[x].nome)

aluno.imprime_aluno()
