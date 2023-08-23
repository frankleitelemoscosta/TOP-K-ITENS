# TOP-K-ITENS

## O PROBLEMA

<p style = "text-align = justify">
Um exemplo clássico de problema que pode ser solucionado utilizando-se hash e heap é o
chamado top k itens. Se trata dos k itens mais recorrentes, para tal foi proposto realizar tal 
tarefa desta forma:
• Crie uma tabela de dispersão (hash) para contar a frequência de cada elemento tok-
enizado da coleção de dados de entrada.
• Crie uma árvore de prioridades (heap) de tamanho k e insira os primeiros k elementos do
hash nela.
Estes são os desafios para resolução do problema. 
</p>

## OBS/ATTENTION!

<p style = "text-align = justify">
Todos os comentarios, alem das variaveis e nome de funções estão escritas na lingua inglesa, com o objetivo de trazer mais inclusão para que qualquer pessoa seja capaz de entender toda codificação.
</p>

<p style = "text-align = justify">
All coments, variables and function names is write in english with the goat of more people read and understand the code. 
</p>

## FASES DE ESPECIFICAÇÃO, PROJETO E IMPLEMENTAÇÃO

<p style = "text-align = justify">
Primeiramente para começar a extrair os dados dos vários arquivos de entrada foi utilizado um contador para contar dentro do loop onde esta ocorrendo o caminhamento letra a letra do arquivo de entrada para que fosse possível concatenar as palavras e formar o nome de cada arquivo, a lógica é converter o inteiro em string e concatenar com o resto do nome que será padrão para a qualquer arquivo que entre no dataset como arquivo de entrada,o padrão de nomeação destes arquivos são: txt01, txt02, e assim sucessivamente, observe que foram definidos apenas dois textos de entrada, para adicionar mais textos a serem processados basta alterar no arquivo Analysis o desvio condicional onde se chama o métod getText dentro do loop while(*ch). 
</p>

<pre>
if(counter < 3){
        mp.mp.clear();
        ch = getText(loc,counter);
}
</pre>

<p style = "text-align = justify">
Era necessário extrair os dados e coloca-los na memória para serem processados e adicionados a estrutura de dados conhecida como tabela de dispersão ou Hash. Para tal requisito foi utilizado o modo de leitura das linguagens utilizadas neste projeto(C e C++) com a biblioteca fstream e como modo de leitura foi utilizado a função wifstream no modo binário, tal função requer apenas o endereço do arquivo a ser lido e o modo de leitura. assim foi adicionado a uma variavela qual foi denominada de buffer neste projeto, e posteriormente seu valor foi retornado a outra que se encontrava no trecho do código onde ocorreu a análise dos dados do arquivo, cujo nome é Analysis, tal função é chamada na função principal da aplicação, que é o marco de inicio de todos os procedimento para cumprir com o objetivo principal do projeto o de fazer um analisador de recorrência de palavras em um texto.
</p>

<p style = "text-align = justify">
Tendo os dados a dispozição para processamento na memoria foi necessário decidir qual estrutura de dados utilizar para armazenar os dados, e alem disso como identificar onde o buffer se encontrava a medida que fosse percorrido letra a letra do arquivo de entrada. Para armazenar as palavras do arquivo de entrada foi utilizado a tabela de dispersão hash, pois a mesma usa como indereçamento uma chave o que facilita a pesquisa, cujo custo computacional é O(1), assim a medida que ocorreu a repetição das palavras no texto foi facil localizar tal palavra na estrutura de dados e contar sua frequencia o qual se faz o principal objetivo.
</p>

<p style = "text-align = justify">
Imagine se fosse usado em vez da hash uma lista para armazenar as palavras, todas as vezes que uma palavra fosse ser inserida a lista teria de ser percorrida novamente para averiguar se essa palavra já não foi inserida. O que não ocorre na estrutura hash, como a pesquisa tem custo O(1).
</p>

<p style = "text-align = justify">
Para realizar o armazenamento de um dado a biblioteca unordered_map recebe um valor e o converte em um inteiro que se torna chave para aquela string ou o tipo que for passado para ser armazenado e se realiza operações bit a bit, alem de outros procedimentos matemáticos. As implementações do std::unordered_map em C++ não usam diretamente nenhum desses métodos específicos de função de hash ("Resto da Divisão", "Meio do Quadrado", "Método da Dobra", "Método da Multiplicação", "Hashing Universal"). Em vez disso, eles usam algoritmos de hash mais complexos e otimizados que são projetados para minimizar colisões e garantir um bom desempenho.
</p>

<p style = "text-align = justify">
No que se refere ao tratamento de colisões o unordered_map faz o seguinte: Se uma chave equivalente a k já existir no contêiner, atribui std:: forward < M > ( obj ) ao mapped_type correspondente à tecla k. Se a chave não existir, insere o novo valor como se fosse por insert, construindo-o a partirvalue_type ( k, std:: forward < M > ( obj ) ).
</p>

<p style = "text-align = justify">
Quanto ao tamanho do hash quando criado a estrutura se tem acesso diretamente a essa informação apartir da versão do C++11, este tamanho depende das politicas da biblioteca utilizada, no caso do unordered_map esse tamanho é de apenas um compartimento ou bucket, que pode ser comprovado através desse algoritmo:
</p>

<pre>
#include< iostream >
#include< unordered_map >

int main() {
    std::unordered_map<int, std::string> myMap;

    // Get the number of the buckets
    size_t numBuckets = myMap.bucket_count();

    std::cout << "Number of buckets: " << numBuckets << std::endl;

    return 0;
}
</pre>

<p style = "text-align = justify">
Para realizar a identificação de onde o buffer se encontrava foi utilizado as seguintes considerações:
</p>

* Este programa deverá ler uma coleção de arquivos contento textos sem nenhuma for-
matação ("arquivo ASCII") onde cada sentença termina por um sinal de pontuação (".",
"?", "!"").
* Cada parágrafo é separado por, pelo menos, uma linha em branco.
* Considere como palavra uma sequência de letras delimitada por espaço em branco, ”col-
una da esquerda”, ”coluna da direita” e símbolos de pontuação.

<p style = "text-align = justify">
Assim quando foi identificado que a variavel com os dados do texto de entrada estava em alguma destas situações a palavra já estava em uma outra variável que foi sendo concatenada letra a letra a cada vez que o loop de leitura foi ocorrendo. A motivação do uso da linguagem C++ neste projeto também se faz mais significativa neste momomento da discução visto que a concatenação de uma string na mesma é mais simples que na linguagem C. 
</p>
<p style = "text-align = justify">
A cada vez que isso ocorria foi sendo adicionado a palavra a estrutura e assim foi até o fim do texto, após o término do processamento do texto por completo a tabela de dispersão continha as k palavras mais recorrentes, nesse caso k = 20, se desejar conhecer um número distinto de palvras mais recorrentes basta alterar porem com isso surge outro entrave, como saber em meio a milhares de palavras quais são as mais recorrentes?, a resposta é: basta usar uma árvore de prioridade heap de tamanho k, fazendo um heap min e percorrendo a hash buscando os valores mais recorrentes, a medida que se percorre a tabela de dispersão do primeiro elemento ao último se compara com o primeiro elemento, que após ter executado o heap min teremos o menor valor no nó raiz. Assim encontrar o elemento que deve sair da árvore foi simples.
</p>

## EXEMPLO DE ENTRADA E SAÍDA

Entrada:

<img src="./img/input.png" width = 50% alt="exemplo de input">

Saída:

<img src="./img/PRINT-CODIGO-PRONTO.png" width = 50% alt="output example">

## INSTRUÇÕES DE COMPILAÇÃO

<p style = "text-align = justify">
Para obter este projeto em sua máquina basta usar o comando no terminal: git clone "link https no topo do repositóiro", tal link esta no topo da página na tag code como mostra a imagem abaixo:
</p>

<img src="./img/protocoloHTTP.png" width = 80% alt="where is the example">

<p style = "text-align = justify">
Este projeto contem um arquivo com um conjunto de diretivas de compilação que podem ser executadas em terminal, as quais são:
</p>

<table border="1">
      <tr><td><u>g++ (nome dos arquivos) -o  (nome do executável)</u></td></tr>
      <tr><td><u>rm -rf (nome do executável)</u></td></tr>
      <tr><td><u>./(nome do executável)</u></td></tr>
</table>


<p style = "text-align = justify">
    <i>As diretrizes de execução deste Make file são:<i>
    <table border="1">
      <tr><td><u>make clean</u></td> <td>Apaga a última compilação realizada contida na pasta objects</td></tr>
      <tr><td><u>make</u></td> <td>Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta objects que esta dentro do repositório build.</td></tr>
      <tr><td><u>make run</u></td> <td>Executa o programa da pasta objects após o programa já estar compilado </td></tr>
    </table>
    <i>Para a execução do programa utilize <u>make</u> para realizar a compilação e logo após utilize <u>make run</u> para executar o programa</i>
</p>

## MÁQUINA DE TESTE

<table style="width: 100%;" border="1">
        <tr align="center" >
            <td colspan="2">
                <div>
                        <br>
                        <p class="sizeText color">Notebook 550XDA Sansung</p>
                        <br>        
                </div>
            </td>
        <tr>
        <tr align="center">
            <td>
               <div>
                    <br>
                    <p class="sizeText color">RAM</p>
                    <br>
               </div> 
            </td>
            <td >
                <br>
                    <p class="sizeText color">8Gb DDR4</p>
                <br>
            </td>
        </tr>
        <tr align="center">
            <td style="width: 20%;">
                <p class="sizeText color">
                    <br>
                    <p class="sizeText color">SO</p>
                    <br>
                </p>
            </td>
            <td >
                <br>
                    <p class="sizeText color">Linux Ubuntu v22.04, 64bits</p>
                <br>
            </td>
        </tr>
        <tr align="center">
            <td style="width: 20%;">
                <br>
                    <p class="sizeText color">    
                        CPU
                    </p>
                <br>
            </td>
            <td >
                <br>
                    <p class="sizeText color">Intel core i5 11° geração 2,40GHz</p>
                <br>
            </td>
        </tr>
    </table>

## REFERÊNCIAS

* https://cplusplus.com/reference/map/map/map/

## AUTOR

<p style = "text-align = justify">
Frank Leite Lemos Costa. Aluno de Engenharia da Computação no <a href = "https://www.cefetmg.br/">CEFET</a>, 4° período.
</p>