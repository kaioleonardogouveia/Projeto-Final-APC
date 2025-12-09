# Projeto-Final-APC

********************************************
Nome: Kaio Leonardo Gouveia da Silva.
Matrícula: 252014368.
********************************************

Apresentação

O programa implementa um simulador básico de caixa de supermercado, permitindo que o usuário adicione produtos a uma lista de compras
e, ao final, exiba um cupom fiscal detalhado com o total a pagar.
**************************************************************************************************************************

Funcionalidades

O projeto se concentra em simular o processo de compra e emissão de comprovante fiscal.

Gerenciamento de Produtos (Estoque Fixo)

Mantém um estoque fixo (estoque[]) de produtos pré-definidos, cada um com um código, nome e preço.

Estruturas de Dados: Utiliza a struct produto para definir cada item no estoque.
**************************************************************************************************************************

Shutterstock

Busca de Produtos (buscar_produto)

Permite que o usuário insira o código de um produto.

Realiza uma busca sequencial no array estoque para encontrar o item correspondente.

Validação: Retorna um ponteiro para o produto encontrado ou NULL se o código não existir.

Adição de Itens à Lista de Compras (adicionar_a_lista)

Recebe o ponteiro do produto e a quantidade desejada pelo usuário.

Adiciona o par produto/quantidade à lista de compras (lista_compras[]).

Estruturas de Dados: Utiliza a struct itemcompra para armazenar o ponteiro para o produto e a quantidade.

Validação: Verifica se o limite máximo de itens na lista (MAX_ITENS) foi atingido.

Exibição do Cupom Fiscal (exibir_total_e_lista)

Percorre toda a lista_compras.

Calcula o subtotal de cada item (preço * quantidade).

Calcula o total geral da compra.

Apresenta uma saída formatada (cupom fiscal) com código, nome, preço unitário, quantidade, subtotal e o total final.

Interface de Usuário (Loop Principal)

Permite que o usuário insira continuamente códigos de produtos e quantidades.

Critério de Parada: O loop é interrompido quando o usuário insere o código 0.
**************************************************************************************************************************
