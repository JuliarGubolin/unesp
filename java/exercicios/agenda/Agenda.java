public class Agenda{
    private Pessoa agenda[] = new Pessoa[10];
    public int numPessoas = 0; 
    
    public void armazenaPessoa(String nome, int idade){
        this.agenda[numPessoas] = new Pessoa();
        this.agenda[numPessoas].setNome(nome);
        this.agenda[numPessoas].setIdade(idade);
        this.numPessoas = this.numPessoas + 1;
    }
    public void removePessoa(String nome){
        
    }
    public void imprimeAgenda(){
        for(int i = 0; i<numPessoas; i++)
            System.out.println("Nome: " + agenda[i].getNome() + "\t Idade: " + agenda[i].getIdade());
    }
    public Agenda (){
    
    }
    public static void main(String []args){
        Agenda ag = new Agenda();
        ag.armazenaPessoa("Alvaro Magri", 24);
        ag.armazenaPessoa("Bruna Tiburcio", 27);
        ag.armazenaPessoa("Joaquim Alves", 50);
        ag.armazenaPessoa("Tirulipa Gontes", 44);
        ag.imprimeAgenda();
    }
}
