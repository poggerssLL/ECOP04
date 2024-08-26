
class Aluno:
    
    def __init__(self, matricula, nome, curso, disciplinas, disciplinas_disponiveis):
        self.matricula = matricula
        self.nome = nome
        self.curso = curso
        self.disciplinas = []
        for disc in disciplinas:
            for disc_disp in disciplinas_disponiveis:
                if disc == disc_disp.nome:
                    self.disciplinas.append(disc_disp)
                    print("Aluno {} matriculado em {}".format(self.nome, disc))
                    break
                else:
                    print("Aluno {} NAO matriculado em {}". format(self.nome, disc))
    def insere_disciplina(self, disciplina, disciplinas_disponiveis):        
        if disciplina in disciplinas_disponiveis:
            self.disciplinas.append(disciplina)
            return True
        else: 
           return False

    

    def imprime_aluno(self):
        print("Nome: {}".format(self.nome))
        print("Matricula: {}".format(self.matricula))
        print("Curso: {}".format(self.curso))
        for x in range (len(self.disciplinas)):

            print(self.disciplinas[x].nome)
