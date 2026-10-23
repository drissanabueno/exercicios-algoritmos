# Exercícios de Algoritmos

Experiências práticas da disciplina **Algoritmos e Pensamento Computacional** (Engenharia de Software, Universidade Positivo, 2026). Uma pasta por exercício.

| Pasta | Tema | Ferramentas |
|---|---|---|
| [`ep1-cesta-basica`](ep1-cesta-basica/) | EP 1: monitoramento do preço da cesta básica em pseudocódigo, com fluxograma | Portugol, Flowgorithm |
| [`ep2-caixa-eletronico`](ep2-caixa-eletronico/) | EP 2: caixa eletrônico em C com menu, decisões e validação de entradas | C, GCC |
| [`ep3-pedagio`](ep3-pedagio/) | EP 3: fluxo semanal de um pedágio com vetor, matriz e laços `for` | C, GCC |

## EP 1: monitoramento da cesta básica

O programa lê o nome e o preço de três produtos em dois meses, calcula a variação percentual de cada um e classifica o resultado em AUMENTO, QUEDA ou ESTÁVEL. Quando a variação de um produto que subiu passa de 10% no mês, aparece um alerta de aumento abusivo junto do resultado.

- [`pseudocodigo.txt`](ep1-cesta-basica/pseudocodigo.txt): o algoritmo inteiro, em quatro partes (leitura, cálculo, classificação e exibição)
- [`flowgorithm/`](ep1-cesta-basica/flowgorithm/): um arquivo `.fprg` para cada parte; o último é o programa completo
- [`imagens/`](ep1-cesta-basica/imagens/): fluxograma e execução de cada parte

O cálculo só divide pelo preço anterior se ele for maior que zero; se não for, a variação fica em 0 e o programa mostra uma mensagem de erro.

Testado com Arroz (20 → 24), Feijão (8 → 7,20) e Leite (5 → 5):

```
Produto: Arroz
Variacao: 20%
Situacao: AUMENTO
ALERTA: aumento abusivo de Arroz (acima de 10% no mes)
------------------------------------------------
Produto: Feijao
Variacao: -10%
Situacao: QUEDA
------------------------------------------------
Produto: Leite
Variacao: 0%
Situacao: ESTAVEL
```

## EP 2: caixa eletrônico (MEU CAIXA)

Um caixa eletrônico simples no terminal, com saldo inicial de R$ 500,00 e as opções de consultar saldo, depositar e sacar.

- O menu fica num `do-while` e só fecha quando a pessoa escolhe `0`
- Cada opção é tratada num `switch`
- No saque, um `if / else if` recusa valor zero ou negativo e **nega o saque maior que o saldo** (o desafio bônus do cenário)
- Opção que não existe cai no `default`; letra no lugar de número é descartada (`scanf` devolve quantos valores leu) e o menu volta sem travar
- Ao sair, o programa mostra o saldo final

Para compilar e rodar:

```bash
gcc ep2-caixa-eletronico/caixa.c -o caixa
./caixa
```

## EP 3: controle de pedágio

O programa lê quantos carros passaram em cada dia de uma semana e mostra um relatório com o total, a média por dia e o dia de maior movimento.

- `int carros[7]` guarda a quantidade de cada dia e `char dias[7][10]` guarda os nomes; os dois usam o mesmo índice `i`
- Três laços `for`: leitura, processamento (soma e busca do pico) e exibição
- A leitura recusa letra e número negativo e pergunta de novo o mesmo dia
- A tabela usa largura fixa no `printf` (`%-10s`, `%8d`) e o dia de pico sai em amarelo e negrito, com a marca `<-- PICO` (o desafio bônus do cenário)

Testado com uma semana de pico no sábado e com outra de pico na segunda, o primeiro dia do vetor ([prints](ep3-pedagio/prints/)).

```bash
gcc ep3-pedagio/pedagio.c -o pedagio
./pedagio
```
