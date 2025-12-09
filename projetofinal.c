#include <stdio.h>
#include <locale.h>
#include <string.h>
typedef struct
{
    int codigo;
    char nome[50];
    float preco;
} produto;

typedef struct {
    produto *item;
    int quantidade;
} itemcompra;

produto estoque[] = {
    {101,"Feijão Preto 1KG",8.00},
    {102,"Feijão Carioca 1KG",7.50},
    {201,"Arroz Branco 1KG",9.00},
    {202,"Arroz Parbolizado 1KG",8.50},
    {301,"Flocão 1KG",3.50},
    {401,"Farinha de Mandioca 1KG",4.00},
    {402,"Farinha de Milho 1KG",6.00},
    {501,"Macarrão Espaguete 1KG",7.00},
    {502,"Macarrão Espaguete Integral 1KG",8.00},
    {601,"Café em Pó Solúvel 500g",25.00},
    {602,"Achocolatado em pó 500g",8.00},
    {701,"Leite UHT Litro",9.50},
    {702,"Leite UHT Desnatado Litro",11.00},
    {703,"Leite em Pó 250g",5.50},
    {704,"Leite em Pó Desnatado 250g",7.50},
    {801,"Biscoito Recheado de Chocolate 100g",3.50},
    {802,"Biscoito Recheado de Morango 100g",3.50},
    {803,"Biscoito Recheado de Limão 100g",3.50},
    {901,"Manteiga com sal 250g",7.50},
    {902,"Manteiga sem sal 250g",9.50},
    {903,"Margarina 250g",5.50},
    {904,"Óleo de Soja Litro",8.50},
    {905,"Azeite de Oliva 500ml",31.50},
    {1010,"Bandeja de ovos (6 unidades)",6.50},
    {1020,"Bandeja de ovos (12 unidades)",12.00},
    {1030,"Bandeja de ovos (20 unidades)",15.00},
    {1040,"Bandeja de ovos (30 unidades)",25.00},
    {1110,"Refrigerante sabor Cola Litro",6.50},
    {1120,"Refrigerante sabor Guaraná Litro",6.50},
    {1130,"Refrigerante sabor Limão Litro",6.50},
    {1210,"Papel Higiênico 6 Rolos",5.00},
    {1220,"Sabão em pó 500g",9.50},
    {1230,"Detergente",4.50},
    {1240,"Creme dental unidade",3.50},
    {1250,"Sabonete unidade",2.50},
    {1300,"Skol Beats GT",6.50}
};

const int numero_produtos = sizeof(estoque) / sizeof(estoque[0]);

#define MAX_ITENS 100
itemcompra lista_compras[MAX_ITENS];
int contador_itens = 0;

produto* buscar_produto(int cod_procurado) {
    for (int i = 0; i < numero_produtos; i++) {
        if (estoque[i].codigo == cod_procurado) {
            return &estoque[i];
        }
    }
    return NULL;
}

void adicionar_a_lista(produto *p, int qtd) {
    if (contador_itens < MAX_ITENS) {
        lista_compras[contador_itens].item = p;
        lista_compras[contador_itens].quantidade = qtd;
        contador_itens++;
        printf("%s (%dx) adicionado(s) à lista. Preço unitário: R$%.2f\n", p->nome, qtd, p->preco);
    } else {
        printf("A lista de compras está cheia (máx. %d itens).\n", MAX_ITENS);
    }
}

void exibir_total_e_lista() {
    float total_geral = 0.0;
    
    printf("\n=================================================\n");
    printf("              CUPOM FISCAL - MERCADINHO APC          \n");
    printf("=================================================\n");
    printf("COD. NOME                 PREÇO QTD SUBTOTAL\n");
    printf("-------------------------------------------------\n");

    if (contador_itens == 0) {
        printf("Nenhum item adicionado.\n");
        printf("-------------------------------------------------\n");
        printf("TOTAL A PAGAR:                              R$ 0.00\n");
        printf("=================================================\n");
        return;
    }

    for (int i = 0; i < contador_itens; i++) {
        produto *p = lista_compras[i].item;
        int qtd = lista_compras[i].quantidade;
        
        float subtotal = p->preco * qtd;
        total_geral += subtotal;
        printf("%-4d %-20s R$ %5.2f %3d R$ %8.2f\n", 
               p->codigo, p->nome, p->preco, qtd, subtotal);
    }

    printf("-------------------------------------------------\n");
    printf("TOTAL A PAGAR:                              R$ %8.2f\n", total_geral);
    printf("=================================================\n");
}
int main()
{
    setlocale(LC_ALL, "Portuguese"); 
    printf("=========================================================================================\n"\
    "BEM-VINDO AO MERCADINHO APC!                                                *************\n"\
    "                                                                            *************\n"\
    "Desenvolvido por Kaio Leonardo em 2025.2 - Universidade de Brasília - FCTE *************\n"\
    "=========================================================================================\n");

    int codigo_usuario;
    int quantidade_usuario;
    produto *produto_encontrado;

 
    while (1) {
        printf("\nInsira o código do produto (ou 0 para finalizar e ver o total): ");
        if (scanf("%d", &codigo_usuario) != 1) {
            while (getchar() != '\n');
            printf("Código inválido. Tente novamente.\n");
            continue;
        }

        if (codigo_usuario == 0) {
            break;
        }

        produto_encontrado = buscar_produto(codigo_usuario);

        if (produto_encontrado != NULL) {

            printf("Produto: %s. Insira a quantidade: ", produto_encontrado->nome);


            if (scanf("%d", &quantidade_usuario) != 1 || quantidade_usuario <= 0) {
                while (getchar() != '\n'); 
                printf("Quantidade inválida ou zero. Item não adicionado.\n");
                continue;
            }
            

            adicionar_a_lista(produto_encontrado, quantidade_usuario);

        } else {

            printf("Produto com código %d não encontrado no estoque.\n", codigo_usuario);
        }
    }
    exibir_total_e_lista();

    printf("\n=================================================\n");
    printf("Pressione ENTER para fechar o programa...");
    while (getchar() != '\n'); 
    getchar();
    return 0;
}