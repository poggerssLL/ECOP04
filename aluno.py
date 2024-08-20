from classes import Aluno
aluno = Aluno("2024004143", "Erick", "ECA",["ECOP"])
aluno.insere_disciplina("Objeto fodase")
print(aluno.disciplinas)
aluno.remove_disciplina("Objeto fodase")
print(aluno.disciplinas)
aluno.imprime_aluno()