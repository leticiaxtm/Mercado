# Mercadinho Stardew Valley - Sistema de Gestão de Produtos

## Descrição
Este projeto é um sistema simples de gestão de produtos, inspirado no famoso jogo *Stardew Valley*. O sistema foi desenvolvido em linguagem C e permite o cadastro de produtos, visualização de produtos, adição ao carrinho, fechamento de pedidos e edição de informações dos produtos cadastrados.

O sistema é baseado em um menu interativo de terminal, onde o usuário pode navegar por diferentes opções para gerenciar o mercadinho.

## Funcionalidades
O sistema implementa as seguintes funcionalidades:
- **Cadastrar Produto**: Adiciona novos produtos ao sistema, com nome, código e preço.
- **Listar Produtos**: Exibe a lista de produtos cadastrados.
- **Comprar Produto**: Adiciona um produto ao carrinho de compras.
- **Visualizar Carrinho**: Mostra os itens atualmente no carrinho, com detalhes como nome, código, quantidade e preço.
- **Fechar Pedido**: Calcula o total da compra e limpa o carrinho após a finalização do pedido.
- **Editar Informações do Produto**: Permite alterar as informações de produtos cadastrados, como nome, preço e código.

## Estrutura do Código
- **main()**: Inicia o programa e chama o menu principal.
- **menu()**: Exibe as opções disponíveis e redireciona o usuário para a função correspondente.
- **cadastrarProduto()**: Permite o cadastro de novos produtos.
- **listarProdutos()**: Lista todos os produtos cadastrados.
- **comprarProduto()**: Adiciona produtos ao carrinho.
- **visualizarCarrinho()**: Mostra os produtos no carrinho.
- **fecharPedido()**: Fecha o pedido e calcula o total.
- **mudarInformacoes()**: Permite editar informações dos produtos já cadastrados.

## Tecnologias Utilizadas
- **Linguagem C**: Linguagem de programação utilizada para desenvolver o sistema.

## Observações
- O sistema foi desenvolvido para estudo e ainda pode ser aprimorado com novas funcionalidades.
- Atualmente, o sistema é limitado a 50 produtos e 50 itens no carrinho.
