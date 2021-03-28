### Projeto ASA
---

#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Descrição do Problema


&nbsp;&nbsp;&nbsp;&nbsp;O Professor João Caracol tem um fascínio por dominós e passa tardes a fazer longas sequências de dominós. Depois chama os vizinhos para todos observarem os dominós a cairem em sequência quando o professor deita alguns dos dominós abaixo.

&nbsp;&nbsp;&nbsp;&nbsp;Como passatempo decidiu desenvolver um algoritmo para conseguir determinar qual o número mínimo de dominós que tem de deitar abaixo com a mão, de forma a garantir que todos os
dominós caiem. Adicionalmente, ficou curioso em saber qual o número de peças pertencente à
maior sequência de dominós a cair, de cada vez que ele deita abaixo com a mão um dominó.

<br>

#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Input

&nbsp;&nbsp;&nbsp;&nbsp;O ficheiro de entrada contém a informação sobre as sequências de dominós, e é definido da seguinte forma:
- Uma linha contendo dois inteiros: o número n de peças de dominó (n ≥ 2), e o número de dependências m a indicar (m ≥ 0);

- Uma lista em que cada linha i contém dois inteiros x e y indicando que se o dominó x cair, então o dominó y também cai.

 &nbsp;&nbsp;&nbsp;&nbsp; Quaisquer inteiros numa linha estão separados por no máximo um espaço em branco, não contendo qualquer outro caractér, a não ser o fim de linha. Assuma que os grafos de input são um DAG (grafo dirigido acíclico).

<br>

#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Output
 
&nbsp;&nbsp;&nbsp;&nbsp; O programa deverá escrever no output dois inteiros k e l separados por um espaço, onde k corresponde ao número mínimo de intervençoes necessárias para garantir que todos os dominós caem e l corresponde ao tamanho da maior sequência de dominós a cair

> **Input** :
    &nbsp;&nbsp;7 8
    &nbsp;&nbsp;3 4
    &nbsp;&nbsp;3 2
    &nbsp;&nbsp;4 6
    &nbsp;&nbsp;4 5
    &nbsp;&nbsp;6 2
    &nbsp;&nbsp;6 5
    &nbsp;&nbsp;5 7
    &nbsp;&nbsp;2 7
**Output** : 
    &nbsp;&nbsp;2 5



