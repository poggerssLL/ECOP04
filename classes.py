class Aluno:
    def __init__(self, matricula, nome, curso, disciplinas):
        self.matricula = matricula
        self.nome = nome
        self.curso = curso
        self.disciplinas = disciplinas
    def insere_disciplina(self, disciplina):        
        self.disciplinas.append(disciplina)
    def remove_disciplina(self, disciplina):
        self.disciplinas.remove(disciplina)
    def imprime_aluno(self):
        print("Nome: {}".format(self.nome))
        print("Matricula: {}".format(self.matricula))
        print("Curso: {}".format(self.curso))
        print("Disciplinas: {}".format(self.disciplinas))