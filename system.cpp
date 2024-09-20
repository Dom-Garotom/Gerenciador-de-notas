    #include <iostream>
    #include <cmath>
    #include <algorithm>
    #include <string>
    #include <fstream>
    #include <vector>
    #include <iomanip>
    #include <iomanip>
    using namespace std ;

    string encapsulador( string String){
        transform(String.begin(), String.end(), String.begin() , ::toupper);

        for (int i = 0; i < String.length() ; i++){
            if (String[i] == ' '){
                String[i] = '_';
            }
        }

        return String ;
    }

    string desencapsulador( string String){
        transform(String.begin(), String.end(), String.begin() , ::tolower);

        for (int i = 0; i < String.length() ; i++){
            if (String[i] == '_'){
                String[i] = ' ';
            }
        }


        return String ;
    }


    string removerCaracteres(string valor){
        string nome = valor;

        nome.erase(remove_if(nome.begin(), nome.end(), [](unsigned char c){
            return isspace(c) || ispunct(c);
        }) , nome.end());

        return nome;
    }


    int numeroDeDisciplinas () {
        string disciplina , codigo;
        int numeroDeDisciplinas = 0;
        

        fstream disciplinas;
        disciplinas.open("../disciplinas.txt" , ios::in);
        while (disciplinas >> disciplina >> codigo){
            numeroDeDisciplinas++;
        }

        disciplinas.close();

        return numeroDeDisciplinas;
    }

    int numeroDeAlunos () {
        string nome, matricula , turma;
        int numeroDeAlunos = 0;
        

        fstream alunos;
        alunos.open("../alunos.txt" , ios::in);
        while (alunos >> nome >> matricula >> turma){
            numeroDeAlunos++;
        }

        alunos.close();

        return numeroDeAlunos;
    }

    void cadastrarAluno(){
        string nome, matricula , turma;
        cout << "Nome do aluno(a):" << endl;
        getline(cin,nome);
        cout << "Matricula do aluno(a):" << endl;
        getline(cin ,matricula); 
        cout << "Turma do aluno(a):" << endl;
        getline(cin , turma);

        nome = encapsulador(nome);
        matricula = removerCaracteres(matricula);
        turma = encapsulador(turma);

        fstream listaDeAlunos;
        listaDeAlunos.open("../alunos.txt", ios::out | ios::app);

        listaDeAlunos << nome << " " << matricula << " " << turma ;

        listaDeAlunos.close();

        cout << endl << "Aluno(a) cadastrado" << endl;
    }

    void cadastrarDisciplinas(){
        string disciplina , codigo;
        cout << "Nome da disciplina a ser adicionada:" << endl;
        getline(cin , disciplina);
        cout << "Codigo da disciplina:" << endl;
        getline(cin , codigo);

        disciplina = encapsulador(disciplina);
        codigo = encapsulador(codigo);

        fstream ListaDeDisciplinas;
        ListaDeDisciplinas.open("../disciplinas.txt", ios::out | ios::app);

        ListaDeDisciplinas << disciplina << " "<< codigo ;

        ListaDeDisciplinas.close();

        cout << endl << "Disciplina cadastrada" << endl;
    }

    string retornarDisciplina(int a){
        int aux = 0;
        int quantidadeDeDisciplina = numeroDeDisciplinas();
        string disciplina , codigo;
        vector<string> todasAsDisciplinas(quantidadeDeDisciplina);

        fstream disciplinas;
        disciplinas.open("../disciplinas.txt" , ios::in);
        while (disciplinas >> disciplina >> codigo){
            todasAsDisciplinas[aux] = desencapsulador(disciplina);
            aux++;
        }

        disciplinas.close();

        return todasAsDisciplinas[a];
    }

    string retornarAluno(int a ){
        int aux = 0;
        int quantidadeDeAluno = numeroDeAlunos();
        string aluno , matricula , turma;
        vector<string> todosOsAlunos(quantidadeDeAluno);
        

        fstream alunos;
        alunos.open("../alunos.txt" , ios::in);
        while (alunos >> aluno >> matricula >> turma){
            todosOsAlunos[aux] = desencapsulador(aluno);
            aux++;
        }

        alunos.close();

        return todosOsAlunos[a];

    }

    void lancarNotas() {
        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas [quantidadeDeAlunos][quantidadeDeDisciplinas][4];


        for (int i = 0; i < quantidadeDeAlunos; i++)
        {
            cout << "Insira a nota do(a) "<< retornarAluno(i) <<  endl ;
            
            for (int j = 0; j < quantidadeDeDisciplinas ; j++)
            {
                cout << "Materia : " << retornarDisciplina(j) <<  endl ;
            
                for (int h = 0; h < 4; h++)
                {
                    cout << "Nota " << h + 1 << endl; 
                    cin >> notas[i][j][h];
                }
                
            }
            
        }

        fstream Notas;
        Notas.open("../notas.txt", ios::out | ios::app);

        for (int i = 0; i < quantidadeDeAlunos; i++)
        {
            if (i ==  0 ) {} else { 
                Notas << endl;
            }
            
            for (int j = 0; j < quantidadeDeDisciplinas ; j++)
            {
                
            
                for (int h = 0; h < 4; h++)
                {
                    Notas << notas[i][j][h] << " ";
                }

                Notas << " ";
                
            }

        }

        Notas.close();
    }

    int encontrarDisciplina () {
        string materia, codigo;
        string valor;
        int cont = 0;
        cout << "Qual o codigo da disciplina : ";
        cin >> valor;

        fstream Disciplinas;
        Disciplinas.open("../disciplinas.txt", ios::in);

        while (Disciplinas >> materia >> codigo){
            if (valor == codigo){
                cout << "codigo : " << codigo << endl;
                cout << "Disciplina : " << materia << endl;
                break;
            }
            cont++;
        }
        
        Disciplinas.close();

        return cont;
    }

    int encontrarAluno () {
        string aluno, matricula , turma;
        string valor;
        int cont = 0;
        cout << "Qual o matricula da aluno(a) : ";
        cin >> valor;

        system("cls");

        fstream alunos;
        alunos.open("../alunos.txt", ios::in);

        if (!alunos){
            cout << "falha ao abrir o arquivo";
        }

        while (alunos >> aluno >> matricula >> turma){
            if (valor == matricula){
                cout << "matricula : " << matricula << endl;
                cout << "aluno : " << aluno << endl;
                break;
            }
            cont++;
        }
        
        alunos.close();

        return cont;
    }

    void consultarNotas(){
        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas [quantidadeDeAlunos][quantidadeDeDisciplinas][4] = {0.0};


        fstream Notas;
        Notas.open("../notas.txt", ios::in);

        for (int i = 0; i < quantidadeDeAlunos; i++)
        { 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++)
            {
                for (int h = 0; h < 4; h++)
                {
                    Notas >> notas[i][j][h];
                }
            }

        }

        Notas.close();

        system("cls");
        

        vector<float> mediasDisciplinares(quantidadeDeDisciplinas, 0.0);
        int aluno =  encontrarAluno() ;
        float media;

        cout<< endl;

        for (int j = 0; j < quantidadeDeDisciplinas ; j++){
            cout<< endl << "Materia : " << retornarDisciplina(j) <<  endl ;
            media = 0;
            for (int h = 0; h < 4; h++){
                cout << "Nota " << h + 1 << " : " << notas[aluno][j][h] << endl;
                media += notas[aluno][j][h];
            }

            mediasDisciplinares[j] = media / 4;
            cout << "Media  : "<< fixed << setprecision(2) << mediasDisciplinares[j] << endl; 

        }
    }

    void consultarNotasDasDisciplinas (){
        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas [quantidadeDeAlunos][quantidadeDeDisciplinas][4] = {0.0};


        fstream Notas;
        Notas.open("../notas.txt", ios::in);

        for (int i = 0; i < quantidadeDeAlunos; i++)
        { 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++)
            {
                for (int h = 0; h < 4; h++)
                {
                    Notas >> notas[i][j][h];
                }
            }

        }

        Notas.close();

        system("cls");

        vector<float> mediasDisciplinares(quantidadeDeDisciplinas, 0.0);
        int disciplina = encontrarDisciplina();

        cout << endl << "Alunos(as) : " << endl; 
        for (int j = 0; j < quantidadeDeAlunos ; j++){
            cout << retornarAluno(j) << " ";
            for (int h = 0; h < 4; h++){
                cout << " | " << fixed << setprecision(2) << notas[j][disciplina][h] ;
            }
            cout << endl;
        }
    }

    void mediasDosAlunos (){
        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas [quantidadeDeAlunos][quantidadeDeDisciplinas][4] = {0.0};


        fstream Notas;
        Notas.open("../notas.txt", ios::in);

        for (int i = 0; i < quantidadeDeAlunos; i++)
        { 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++)
            {
                for (int h = 0; h < 4; h++)
                {
                    Notas >> notas[i][j][h];
                }
            }

        }

        Notas.close();

        system("cls");
        

        vector<vector<float>> mediasDisciplinares(quantidadeDeAlunos, vector<float>(quantidadeDeDisciplinas, 0.0));
        float media;

        cout<< endl;

        cout << "Medias dos alunos em : ";
        for (int i = 0 ; i < quantidadeDeDisciplinas ; i++){
            cout << retornarDisciplina(i) << " ";
        }

        cout << endl;

        for (int i = 0; i < quantidadeDeAlunos; i++){ 
            cout << retornarAluno(i) << " : ";

            for (int j = 0; j < quantidadeDeDisciplinas ; j++){
                
                for (int h = 0; h < 4; h++){
                    media += notas[i][j][h];
                }

                mediasDisciplinares[i][j] = media / 4;
                cout << mediasDisciplinares[i][j] << " | "; 
                media = 0;

            }

            cout << endl;

        }
    }

    void mediasGeraisDosAlunos(){
        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas [quantidadeDeAlunos][quantidadeDeDisciplinas][4] = {0.0};


        fstream Notas;
        Notas.open("../notas.txt", ios::in);

        for (int i = 0; i < quantidadeDeAlunos; i++)
        { 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++)
            {
                for (int h = 0; h < 4; h++)
                {
                    Notas >> notas[i][j][h];
                }
            }

        }

        Notas.close();

        system("cls");
        

        vector<vector<float>> mediasDisciplinares(quantidadeDeAlunos, vector<float>(quantidadeDeDisciplinas, 0.0));
        vector<float> mediasGerais(quantidadeDeAlunos);
        float media;

        for (int i = 0; i < quantidadeDeAlunos; i++){ 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++){
                for (int h = 0; h < 4; h++){
                    media += notas[i][j][h];
                }

                mediasDisciplinares[i][j] = media / 4;
                media = 0;

            }
        }

        cout << "Medias gerais dos alunos(as) :" << endl;
        for (int i = 0; i < quantidadeDeAlunos; i++){ 
            cout << retornarAluno(i) << " : ";
            for (int j = 0; j < quantidadeDeDisciplinas ; j++){
                media += mediasDisciplinares[i][j];
            }
            mediasGerais[i] = media / quantidadeDeDisciplinas;
            media = 0; 

            cout << mediasGerais[i] << endl;
        }
    }

    vector<float> retornarMediasGeraisDosAlunos(){

        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas [quantidadeDeAlunos][quantidadeDeDisciplinas][4] = {0.0};


        fstream Notas;
        Notas.open("../notas.txt", ios::in);

        for (int i = 0; i < quantidadeDeAlunos; i++)
        { 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++)
            {
                for (int h = 0; h < 4; h++)
                {
                    Notas >> notas[i][j][h];
                }
            }

        }

        Notas.close();

        vector<vector<float>> mediasDisciplinares(quantidadeDeAlunos, vector<float>(quantidadeDeDisciplinas, 0.0));
        vector<float> mediasGerais(quantidadeDeAlunos);
        float media;

        for (int i = 0; i < quantidadeDeAlunos; i++){ 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++){
                for (int h = 0; h < 4; h++){
                    media += notas[i][j][h];
                }

                mediasDisciplinares[i][j] = media / 4;
                media = 0;

            }
        }

        for (int i = 0; i < quantidadeDeAlunos; i++){ 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++){
                media += mediasDisciplinares[i][j];
            }
            mediasGerais[i] = media / quantidadeDeDisciplinas;
            media = 0; 
        }

        return mediasGerais;


    }

    vector<vector<float>>  retornarMediaDosAlunos(){
        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas [quantidadeDeAlunos][quantidadeDeDisciplinas][4] = {0.0};


        fstream Notas;
        Notas.open("../notas.txt", ios::in);

        for (int i = 0; i < quantidadeDeAlunos; i++)
        { 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++)
            {
                for (int h = 0; h < 4; h++)
                {
                    Notas >> notas[i][j][h];
                }
            }

        }

        Notas.close();

        vector<vector<float>> mediasDisciplinares(quantidadeDeAlunos, vector<float>(quantidadeDeDisciplinas, 0.0));
        float media;


        for (int i = 0; i < quantidadeDeAlunos; i++){ 
            for (int j = 0; j < quantidadeDeDisciplinas ; j++){
                
                for (int h = 0; h < 4; h++){
                    media += notas[i][j][h];
                }

                mediasDisciplinares[i][j] = media / 4; 
                media = 0;

            }
        }

        return mediasDisciplinares;

        
    }

    vector<string>encontrarAlunoRelatorio (string valor, bool indexAluno = false){
        string aluno, matricula , turma;
        vector<string>informacoes(4);
        vector<string>posicaoDoAluno(1);
        bool encontrado;
        int index = 0;
        



        fstream alunos;
        alunos.open("../alunos.txt", ios::in);

        while (alunos >> aluno >> matricula >> turma){
            if (valor == matricula){
                informacoes[0] = aluno;
                informacoes[1] = matricula;
                informacoes[2] = turma;
                informacoes[3] = to_string(index);
                encontrado = true;
                break;
            }
            index++;
        }
        
        alunos.close();
        
        if (indexAluno){
            posicaoDoAluno[0] = index;
            return posicaoDoAluno;
        }

        if (encontrado) {
            return informacoes;
        } else {
            cout << "Aluno não encontrado!" << endl;
            return{};
        }


    }

    int encontrarIndiceAluno (string valor){
        string aluno, matricula , turma;
        bool encontrado;
        int index = 0;

        fstream alunos;
        alunos.open("../alunos.txt", ios::in);

        while (alunos >> aluno >> matricula >> turma){
            if (valor == matricula){
                encontrado = true;
                break;
            }
            index++;
        }
        
        alunos.close();
        
        if (encontrado) {
            return index;
        } else {
            cout << "Aluno não encontrado!" << endl;
            return{};
        }


    }

    void gerarRelatorio(){
        string valor;
        cout << "Qual a matricula do(a) aluno(a) : ";
        cin >> valor;

        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas[quantidadeDeAlunos][quantidadeDeDisciplinas][4] = {0.0};

        fstream Notas;
        Notas.open("../notas.txt", ios::in);

        for (int i = 0; i < quantidadeDeAlunos; i++) {
            for (int j = 0; j < quantidadeDeDisciplinas; j++) {
                for (int h = 0; h < 4; h++) {
                    Notas >> notas[i][j][h];
                }
            }
        }
        Notas.close();


        vector<string> informacoes = encontrarAlunoRelatorio(valor);
        vector<float> mediasGerais = retornarMediasGeraisDosAlunos();
        vector<vector<float>> mediasDisciplinares(quantidadeDeAlunos, vector<float>(quantidadeDeDisciplinas, 0.0));
        mediasDisciplinares = retornarMediaDosAlunos();
        
        int posicaoDoAluno = encontrarIndiceAluno(valor);


        fstream relatorio;
        relatorio.open("../relatorio.txt", ios::out);
       
        relatorio << "RELATÓRIO ESCOLAR" << endl << endl;
        relatorio << "------------------------------------" << endl;
        relatorio << "Nome: " << informacoes[0] << endl;
        relatorio << "Matricula " << informacoes[1] << endl;
        relatorio << "Turma: " << informacoes[2] << endl;
        relatorio << "------------------------------------" << endl;
        relatorio << left << setw(15) << "Disciplinas " <<"| N1 | N2 | N3 | N4 | Média" <<  endl;

        for (int i = 0 ; i < quantidadeDeDisciplinas; i++){
            relatorio << left << setw(12) << retornarDisciplina(i) ;
            for (int j = 0 ; j < 5; j++){
                if (j == 4){
                    relatorio << " | " << mediasDisciplinares[posicaoDoAluno][i] ;
                    break;
                } 
                relatorio << "  |  " << notas[posicaoDoAluno][i][j] ;
            }

            relatorio << endl;
        }

        relatorio << endl << endl << "Observacoes: " << endl;

        if (mediasGerais[posicaoDoAluno] >= 6.0) {  
            relatorio << "Prezado(a) " << informacoes[0] << "," << endl;
            relatorio << "Apos a conclusao das atividades e avaliacoes deste periodo, "
                      << "sua media geral foi de " << mediasGerais[posicaoDoAluno] << "." << endl;
            relatorio << "Com isso, temos o prazer de informa-lo(a) que voce foi aprovado(a)." << endl;
            relatorio << "Parabenizamos pelo seu esforco e dedicacao ao longo do curso." << endl
                      << "Continue mantendo seu compromisso com os estudos, pois o seu desempenho "
                      << "reflete diretamente sua dedicacao." << endl
                      << "Desejamos sucesso em suas proximas etapas academicas." << endl;
            relatorio << "Atenciosamente," << endl << "IfRN";
        } else {
            relatorio << "Prezado(a) " << informacoes[0] << "," << endl;
            relatorio << "Apos a conclusao das atividades e avaliacoes deste periodo, "
                      << "sua media geral foi de " << mediasGerais[posicaoDoAluno] << "." << endl;
            relatorio << "Infelizmente, com esse resultado, voce foi reprovado(a)." << endl;
            relatorio << "Sabemos que os resultados podem nao ter sido os esperados, "
                      << "mas acreditamos que, com mais dedicacao e foco, voce podera melhorar seu desempenho." << endl;
            relatorio << "Recomendamos que utilize este momento como uma oportunidade para evoluir "
                      << "e planejar suas proximas acoes com mais confianca." << endl;
            relatorio << "Estamos a disposicao para auxilia-lo(a) no que for necessario." << endl;
            relatorio << "Atenciosamente," << endl << "IfRN";
        }

        relatorio.close();

        cout << "Relatorio escolar gerado com sucesso" << endl;

    }

    void showRelatorio(){
        string valor;
        cout << "Qual a matricula do(a) aluno(a) : ";
        cin >> valor;

        int quantidadeDeDisciplinas = numeroDeDisciplinas();
        int quantidadeDeAlunos = numeroDeAlunos();
        float notas[quantidadeDeAlunos][quantidadeDeDisciplinas][4] = {0.0};

        fstream Notas;
        Notas.open("../notas.txt", ios::in);

        for (int i = 0; i < quantidadeDeAlunos; i++) {
            for (int j = 0; j < quantidadeDeDisciplinas; j++) {
                for (int h = 0; h < 4; h++) {
                    Notas >> notas[i][j][h];
                }
            }
        }
        Notas.close();


        vector<string> informacoes = encontrarAlunoRelatorio(valor);
        vector<float> mediasGerais = retornarMediasGeraisDosAlunos();
        vector<vector<float>> mediasDisciplinares(quantidadeDeAlunos, vector<float>(quantidadeDeDisciplinas, 0.0));
        mediasDisciplinares = retornarMediaDosAlunos();
        int posicaoDoAluno = encontrarIndiceAluno(valor);
        

        cout << "RELATORIO ESCOLAR" << endl << endl;
        cout << "------------------------------------" << endl;
        cout << "Nome: " << informacoes[0] << endl;
        cout << "Matricula " << informacoes[1] << endl;
        cout << "Turma: " << informacoes[2] << endl;
        cout << "------------------------------------" << endl;
        cout << left << setw(15) << "Disciplinas " <<"| N1 | N2 | N3 | N4 | Média" <<  endl;

        for (int i = 0 ; i < quantidadeDeDisciplinas; i++){
            cout << left << setw(12) << retornarDisciplina(i) ;
            for (int j = 0 ; j < 5; j++){
                if (j == 4){
                    cout << " | " << mediasDisciplinares[posicaoDoAluno][i] ;
                    break;
                } 
                cout << "  |  " << notas[posicaoDoAluno][i][j] ;
            }

            cout << endl;
        }

        cout << endl << endl << "Observacoes: " << endl;

        if (mediasGerais[posicaoDoAluno] >= 6.0) {  
            cout << "Prezado(a) " << informacoes[0] << "," << endl;
            cout << "Apos a conclusao das atividades e avaliacoes deste periodo, "
                      << "sua media geral foi de " << mediasGerais[posicaoDoAluno] << "." << endl;
            cout << "Com isso, temos o prazer de informa-lo(a) que voce foi aprovado(a)." << endl;
            cout << "Parabenizamos pelo seu esforco e dedicacao ao longo do curso." << endl
                      << "Continue mantendo seu compromisso com os estudos, pois o seu desempenho "
                      << "reflete diretamente sua dedicacao." << endl
                      << "Desejamos sucesso em suas proximas etapas academicas." << endl;
            cout << "Atenciosamente," << endl << "IfRN";
        } else {
            cout << "Prezado(a) " << informacoes[0] << "," << endl;
            cout << "Apos a conclusao das atividades e avaliacoes deste periodo, "
                      << "sua media geral foi de " << mediasGerais[posicaoDoAluno] << "." << endl;
            cout << "Infelizmente, com esse resultado, voce foi reprovado(a)." << endl;
            cout << "Sabemos que os resultados podem nao ter sido os esperados, "
                      << "mas acreditamos que, com mais dedicacao e foco, voce podera melhorar seu desempenho." << endl;
            cout << "Recomendamos que utilize este momento como uma oportunidade para evoluir "
                      << "e planejar suas proximas acoes com mais confianca." << endl;
            cout << "Estamos a disposicao para auxilia-lo(a) no que for necessario." << endl;
            cout << "Atenciosamente," << endl << "IfRN";
        }


        cout << endl;
        cout << "Relatorio escolar gerado com sucesso" << endl;

    }

int main() {
    int opcao;
    system("cls");

    do {
        cout << "Escolha uma opcao:" << endl;
        cout << "1. Cadastrar Aluno" << endl;
        cout << "2. Cadastrar Disciplina" << endl;
        cout << "3. Lancar Notas" << endl;
        cout << "4. Consultar Notas de um Aluno" << endl;
        cout << "5. Consultar Notas de uma Disciplina" << endl;
        cout << "6. Ver Medias dos Alunos" << endl;
        cout << "7. Ver Medias Gerais dos Alunos" << endl;
        cout << "0. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;
        cin.ignore(); 

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                cadastrarDisciplinas();
                break;
            case 3:
                lancarNotas();
                break;
            case 4:
                consultarNotas();
                break;
            case 5:
                consultarNotasDasDisciplinas();
                break;
            case 6:
                mediasDosAlunos();
                break;
            case 7:
                mediasGeraisDosAlunos();
                break;
            case 8:
                cout << "Você gostaria de abrir o relatorio em um arquivo ou imprimir em tela ?" << endl;
                cout << " 1 - para abrir em um arquivo separado" << endl;
                cout << " 2 - para mostrar na tela" << endl;
                int aux;
                cin >> aux;

                if (aux == 1){
                    gerarRelatorio();
                } else {
                    showRelatorio();
                }

                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

}
        
    
