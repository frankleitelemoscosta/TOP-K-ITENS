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

## FASES DE ESPECICAÇÃO, PROJETO E IMPLEMENTAÇÃO

<p style = "text-align = justify">
Primeiramente para começar a extrair os dados dos varios arquivos de entrada foi utilizado um vetor com os nomes dos arquivos de entradas txt01, txt02. Era necessário extrair os dados e coloca-los na memória para serem processados e adicionados a estrutura de dados conhecida como tabela de dispersão ou Hash. Para tal requisito foi utilizado o modo de leitura binária que na sintaxe das linguagens utilizadas neste projeto(C e C++), se usa a biblioteca fstream e para leitura foi utilizado a função wifstream
</p>

## INSTRUÇÕES DE COMPILAÇÃO

<p style = "text-align = justify">
Para obter este projeto em sua máquina basta usar o comando no terminal: git clone "link https no topo do repositóiro", tal link esta no topo da página na tag code como mostra a imagem abaixo:
</p>

<img src="./img/protocoloHTTP.png" width = 80% alt="onde esta o link">

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

## AUTOR

<p style = "text-align = justify">
Frank Leite Lemos Costa. Aluno de Engenharia da Computação no <a href = "https://www.cefetmg.br/">CEFET</a>, 4° período.
</p>