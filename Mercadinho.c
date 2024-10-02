#include <stdio.h>
#include <unistd.h>
#include <string.h>
// Funções declaradas
void cadastrarProduto();// Função para cadastrar um novo produto
void menu();// Função que exibe o menu principal
void listarProdutos();// Função que lista os produtos cadastrados
void comprarProduto();// Função para adicionar um produto ao carrinho de compras
void visualizarCarrinho();// Função que exibe os itens no carrinho
void fecharPedido();// Função para finalizar a compra
void infoProduto();//Função que exibe informações detalhadas de um produto
void mudarInformacoes();// Função  que permite modificar informações de produtos cadastrados
//Structs para armazenar produtos e o carrinho
typedef struct
{
    int codigo;
    char nome[30];
    float preco;
} Produto;
typedef struct
{
    Produto produto;
    int quantidade;
} Carrinho;

//Arrays para armazenar produtos e carrinho de compras
Produto produtos[50];   // Array que armazena até 50 produtos cadastrados
Carrinho carrinho[50]; // Array que armazena até 50 produtos no carrinho
// Variáveis globais para controlar a quantidade de produtos e itens no carrinho
int quantidadeP = 0; // quantidade de produtos
int quantidadeC = 0; //quantidade de produtos no carrinho

int main()
{
    // Inicia o sistema chamando o menu principal
    menu();

    return 0;
}
// Função que exibe o menu principal e navega pelas opções
void menu()
{
    int op; // Variável para armazenar a opção escolhida
    do
    {
        system("cls");// Limpa a tela e exibe as opções do menu
        printf("**\n");
        printf("\nMercadinho Stardew Valley\n");
        printf("\n**\n");
        printf("Ola seja bem-vindo(a) ao mercadinho Stardew Valley!:\n");
        printf("1-Cadastrar Produto:\n");
        printf("2-Listar Produtos:\n");
        printf("3-Comprar Produto:\n");
        printf("4-Visualizar Carrinho:\n");
        printf("5-Fechar Pedido:\n");
        printf("6-Sair do Sistema:\n");

         // Lê a opção do usuário
        printf("Informe um numero de 1 ate 6:\n");
        scanf("%d", &op);
          // Navega para a função correspondente à opção escolhida
        switch (op)
        {

        case 1:
            cadastrarProduto();// Chama a função para cadastrar um produto
            break;
        case 2:
            listarProdutos(); // Chama a função para listar os produtos

            break;
        case 3:
            comprarProduto(); // Chama a função para comprar um produto
            break;
        case 4:
            visualizarCarrinho(); // Chama a função para visualizar o carrinho
            break;
        case 5:
            fecharPedido(); // Chama a função para finalizar o pedido
            break;
        case 6:
            printf("Saindo do sistema......"); // Sai do sistema
            break;
        default:
            printf("Opcao invalida!!");// Exibe mensagem de erro se a opção for inválida
            break;
        }
    } while (op != 6);// Continua mostrando o menu até o usuário escolher sair
}
// Função para cadastrar um novo produto
void cadastrarProduto()
{
    int tempcodigo, flag;
    printf("\n1-Cadastrando produtos:\n");
    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(produtos[quantidadeP].nome, sizeof(produtos[quantidadeP].nome), stdin);
    produtos[quantidadeP].nome[strcspn(produtos[quantidadeP].nome, "\n")] = '\0';
    printf("Digite o preco do produto: ");
    scanf("%f", &produtos[quantidadeP].preco);
    do
    {
        flag = 0;
        printf("Digite o codigo do produto: ");
        scanf("%d", &tempcodigo);

         // Percorre os produtos para verificar se o código já foi usado
        for (int i = 0; i < quantidadeP; i++)
        {
            if (produtos[i].codigo == tempcodigo)
            {
                printf("Esse codigo ja existe. por favor digite um codigo novo:\n");
                flag = 1; // Se o código já existir, define a flag como 1
                break;
            }
        }
    } while (flag); // Repete até o usuário digitar um código não utilizado
    produtos[quantidadeP].codigo = tempcodigo;// Atribui o código ao produto
    quantidadeP++;// Incrementa o número de produtos cadastrados
    printf("Produto cadastrado com sucesso! \n");
    sleep(1);// Pausa para exibir a mensagem
}
// Função que lista todos os produtos cadastrados
void listarProdutos()
{
    printf("\n2-Lista dos produtos cadastrados:\n");
     // Exibe os produtos cadastrados
    for (int i = 0; i < quantidadeP; i++)
    {
        printf("---------------------------\n");
        printf("Codigo do produto: %d", produtos[i].codigo);
        printf("\nNome do produto: %s", produtos[i].nome);
        printf("\nPreco do produto: %.2f", produtos[i].preco);
        printf("\n---------------------------\n");
    }
     // Caso não haja produtos cadastrados, exibe uma mensagem
    if (quantidadeP == 0)
    {
        printf("\nNenhum produto cadastrado!\n");
        sleep(1);
    }
    system("pause"); // Pausa a execução até o usuário pressionar uma teclac
    mudarInformacoes(); // Chama a função para mudar as informações do produto, se necessário
}
// Função para exibir informações de um produto específico
void infoProduto()
{
 // Percorre os produtos cadastrados e exibe as informações do produto com o código fornecido
    for (int i = 0; i < quantidadeP; i++)
    {
        int x;
        printf("---------------------------\n");
         // Lê o código do produto do usuário
        printf("\n Digite o codigo do produto para mostrar as informacoes do produto:\n");
        scanf("%d", &x);
        printf("\n---------------------------\n");
        if (x == produtos[quantidadeP].codigo)
        {
            printf("Nome do produto:%s", produtos[i].nome);
            printf("\nPreco do produto: %.2f", produtos[i].preco);
            printf("\nCodigo do produto: %d", produtos[i].codigo);
            system("pause");
        }
        else
        {  // Caso o código não seja encontrado, exibe uma mensagem de erro
            printf("Codigo do produto inexistente!\n");
            sleep(1);
        }
    }
}
// Função para exibir os itens do carrinho de compras
void visualizarCarrinho()
{
    printf("Itens do Carrinho:\n");
    // Exibe os itens no carrinho
    for (int i = 0; i < quantidadeC; i++)
    {
        printf("---------------------------\n");
        printf("Nome do produto: %s \n", carrinho[i].produto.nome);
        printf("Preco do produto: %.2f \n", carrinho[i].produto.preco);
        printf("Codigo do produto: %d \n", carrinho[i].produto.codigo);
        printf("Quantidade do produto: %d \n", carrinho[i].quantidade);
        printf("---------------------------\n\n");
    }
     
    int qnt = 0;
    for (int i = 0; i < quantidadeC; i++)
    {
        qnt += carrinho[i].quantidade;
    }
    // Exibe a quantidade total de produtos no carrinho
    printf("Quantidade de produtos no carrinho: %d \n", qnt);
    
    int x, cod;
    // Pergunta ao usuário se ele deseja remover algum produto do carrinho
    printf("\nDeseja remover algo da sua lista de compras? Se sim digite 1 senao digite 2:");
    scanf("%d", &x);
    if (x == 1)
    {
    // Lê o código do produto a ser removido
        printf("Digite o codigo do produto no qual voce deseja remover: ");
        scanf("%d", &cod);
        // Verifica se o carrinho está vazio se sim exibe a mensagem
        if (quantidadeC == 0)
        {
            printf("O carrinho esta vazio! Não e possível remover o produto desejado.\n");
            sleep(1);
            return;
        }
         // Copia os produtos restantes para um array auxiliar, removendo o produto desejado
        Carrinho aux[50];
        int encontrado = 0;
        for (int i = 0; i < quantidadeC; i++)
        {
            if (cod == carrinho[i].produto.codigo)
            {
                encontrado = 1;
            }
            else
            {
                
                aux[i] = carrinho[i];// Atribui o auxiliar aos produtos do carrinho
            }
        }
        if (encontrado)
        {
            quantidadeC--;//remove o produto desejado do carrinho
            for (int i = 0; i < quantidadeC; i++)
            {// Atualiza o carrinho e a quantidade de itens
                carrinho[i] = aux[i];
            }
            printf("Produto removido com sucesso!\n");
        }
        else
        {
            printf("Codigo nao encontrado no carrinho!\n");
            sleep(1);
        }
    }
    system("pause");
}
// Função para finalizar o pedido
void fecharPedido()
{
    int x;
    //Se a quantidade de produtos no carrinho for igual a 0 exibe a mensagem
    if (quantidadeC == 0)
    {
        printf("O carrinho está vazio! Não é possível fechar o pedido.\n");
        return;
    }

    float somaTotal = 0.0;
    for (int i = 0; i < quantidadeC; i++)
    {
        somaTotal += carrinho[i].produto.preco * carrinho[i].quantidade;
    }//Pergunta ao usuario se ele esqueceu de adicionar algum produto
    printf("Esqueceu de adicionar algo no pedido? Se sim digite 1 senao digite 2:");
    scanf("%d", &x);
    if (x == 1)
    {
        return comprarProduto();//Se a resposta for sim retorna a função de comprar produto
    }
    else
    { // Exibe o total da compra
        printf("Obrigada pela compra e volte sempre!! A soma total do seu pedido e de: R$ %.2f\n", somaTotal);
        somaTotal = 0;
        Carrinho aux[50];
        for (int i = 0; i < quantidadeC; i++)
        {
            carrinho[i] = aux[i];
        }
        quantidadeC = 0;
    }

    system("pause");
}
//Função para verificar se tem ou não o produto no carrinho
void temNoCarrinho()
{
    int x;// Armazena o código do produto digitado pelo usuário
    int encontrado = 0;// Flag que indica se o produto foi encontrado no carrinho
    int existe = 0; // Flag que indica se o produto existe na lista de produtos
// Solicita ao usuário que digite o código do produto que deseja verificar
    printf("Digite o codigo do produto para verificar se ele esta no carrinho: ");
    scanf("%d", &x);
      // Laço para verificar se o código do produto existe na lista de produtos
    for (int i = 0; i < quantidadeP; i++)
    {
        if (x == produtos[i].codigo)
        {
            existe = 1;// Marca que o produto existe
            break; // Sai do laço
        }
    }
// Se o produto não existir, exibe uma mensagem de erro e encerra a função
    if (!existe) 
    {
        printf("O produto não existe! Digite um código valido.\n");
        return;// Retorna sem continuar
    }
    // Laço para verificar se o produto está no carrinho de compras
    for (int i = 0; i < quantidadeC; i++)
    {
        if (x == carrinho[i].produto.codigo) // Se o código do produto for encontrado no carrinho
        {
            encontrado = 1;// Marca que o produto foi encontrado no carrinho
            break; // Sai do laço
        }
    }

    if (encontrado)// Se o produto foi encontrado no carrinho, exibe a mensagem correspondente
    {
        printf("O produto está no carrinho de compras!\n");
    }
    else// Caso contrário, informa que o produto não está no carrinho
    {
        printf("O produto não está no carrinho.\n");
    }
}
// Função para adicionar um produto ao carrinho
void comprarProduto()
{ // Declaração das variáveis
    int cod, encontrado = 0, qtd, encontrarcodigoproduto = 0;
    Produto tempproduto;
    printf("\n Adicionando produtos:\n");
   // Solicita ao usuário o código do produto que deseja adicionar ao carrinho
    printf("Digite o codigo do produto para adiciona-lo no carrinho: ");
    scanf("%d", &cod);
// Laço para verificar se o código do produto existe na lista de produtos cadastrados
    for (int i = 0; i < quantidadeP; i++)
    {  // Se o código do produto for encontrado
        if (cod == produtos[i].codigo)
        {
            encontrarcodigoproduto = 1;  // Marca que o código foi encontrado
             // Exibe as informações do produto selecionado
            printf("Nome do produto: %s\n", produtos[i].nome);
            printf("Preco do produto: %.2f\n", produtos[i].preco);
            printf("Codigo do produto: %d\n", produtos[i].codigo);

            // Solicita a quantidade desejada do produto
            printf("Digite a quantidade que deseja comprar: ");
            scanf("%d", &qtd);

            tempproduto = produtos[i];// Armazena o produto temporariamente para adicioná-lo ao carrinho
            if (qtd <= 0)// Verifica se a quantidade informada é válida (maior que zero)
            {
                printf("Quantidade inválida! A quantidade deve ser maior que 0.\n");
                return;// Retorna sem adicionar ao carrinho
            }
            // Verifica se o produto já está no carrinho
            for (int i = 0; i < quantidadeC; i++)
            {
                if (cod == carrinho[i].produto.codigo)
                { // Caso o produto já esteja no carrinho, apenas atualiza a quantidade
                    carrinho[i].quantidade += qtd; 
                    encontrado = 1;// Marca que o produto já estava no carrinho
                    break;// Sai do laço
                }
            }
             // Se o produto não estava no carrinho e ainda há espaço para adicionar novos itens
            if (!encontrado && quantidadeC < 50)
            {  // Adiciona o produto e a quantidade ao carrinho
                carrinho[quantidadeC].quantidade = qtd;
                carrinho[quantidadeC].produto = tempproduto;
                quantidadeC++;// Incrementa o número de itens no carrinho
                printf("Produto adicionado com sucesso! \n");
            }
            else if (quantidadeC > 50)// Verifica se o limite de itens no carrinho foi excedido
            {
                printf("Limite de itens excedido!\n");
            }
            sleep(1); // Pausa de 1 segundo para exibir a mensagem
            break; // Sai do laço de produtos cadastrados
        }
    }
    // Se o código do produto não foi encontrado
    if (!encontrarcodigoproduto)
    {
        printf("Codigo inexistente!\n");
        sleep(1);// Pausa de 1 segundo para exibir a mensagem
    }
    int op;
    // Pergunta ao usuário se deseja visualizar o carrinho após adicionar o produto
    printf("Deseja verificar se tem algum produto faltando no carrinho? Se sim digite 1 senao digite 2: ");
    scanf("%d", &op);
    // Se o usuário deseja visualizar o carrinho
    if (op == 1)
    {
        printf("\n");
        visualizarCarrinho(); // Chama a função que exibe os produtos do carrinho
    }
}
// Função para mudar informações de um produto cadastrado
void mudarInformacoes()
{
    int op, cod, op2, c, encontrado = 0;// Variáveis para armazenar opções, código do produto e flags
    // Pergunta ao usuário se deseja mudar alguma informação dos produtos cadastrados
    printf("Deseja mudar alguma informacao dos produtos cadastrados? Se sim digite 1 senao digite 2: \n");
    scanf("%d", &op);
    printf("\n---------------------------\n");
      // Se o usuário escolheu a opção de modificar (1)
    if (op == 1)
    {// Solicita o código do produto que deseja altera
        printf("Digite o codigo do produto para mudar suas informacoes:\n");
        scanf("%d", &cod);

        printf("\n---------------------------\n");
        for (int i = 0; i < quantidadeP; i++) // Percorre a lista de produtos para encontrar o código informado
        {
            if (cod == produtos[i].codigo)// Se o código do produto for encontrado
            {
                encontrado = 1;// Marca que o produto foi encontrado
                // Limpa o buffer de entrada
                printf("Mudando o nome:\n");
                fflush(stdin);// Limpa o buffer de entrada
                fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);// Lê o novo nome do produto
                produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';// Remove o caractere de nova linha
                // Permite ao usuário alterar o preço do produto
                printf("Mudando o preco:\n");
                scanf("%f", &produtos[i].preco);
                // Pergunta se o usuário deseja alterar o código do produto também
                printf("\n Deseja mudar o codigo tambem? Digite 1 para modificar e 2 para sair:\n");
                scanf("%d", &op2);
                 // Se o usuário escolher alterar o código (1)
                if (op2 == 1)
                { // Solicita o novo código
                    printf("Mudando o codigo:\n");
                    scanf("%d", &c);
                    int encontrado = 0;// Flag para verificar se o novo código já está em uso
                     // Verifica se o novo código já está sendo utilizado
                    for (int j = 0; j < quantidadeP; j++)
                    {

                        if (c == produtos[j].codigo)
                        {
                            encontrado = 1;// Marca que o código já existe
                            printf("Por favor digite um codigo que não esteja sendo utilizado!\n");
                            break;// Sai do laço se o código já existir

                            sleep(1);
                        }
                    } // Se o novo código não estiver em uso, atribui ao produto
                    if (!encontrado)
                        produtos[i].codigo = c;
                }// Se o usuário escolher uma opção inválida para a alteração de código
                else if (op2 > 2 || op2 <= 0)
                {
                    printf("ERRO! digite uma opcao valida!\n");
                    sleep(1);
                }// Se o código não for alterado, finaliza a modificação
                else
                {
                    printf("Produto modificado com sucesso!");
                    sleep(1);
                }
                break; // Sai do laço após modificar o produto
            }
        }
        // Se o código do produto não foi encontrado, exibe uma mensagem de erro
        if (!encontrado)
            printf("Codigo nao encontrado! \n");
        sleep(1);
    }
    // Se o usuário escolheu não modificar nada (2)
    else
    {
        printf("SAINDO....");
        sleep(1);
        return menu();// Retorna ao menu principal
    }
}