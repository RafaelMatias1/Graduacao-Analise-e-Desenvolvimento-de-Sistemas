// Utilitários para gerenciar localStorage
export const STORAGE_KEY = 'ministore_produtos';

// Buscar todos os produtos
export const getProdutos = () => {
  try {
    const produtos = localStorage.getItem(STORAGE_KEY);
    return produtos ? JSON.parse(produtos) : [];
  } catch (error) {
    console.error('Erro ao buscar produtos:', error);
    return [];
  }
};

// Salvar produto
export const salvarProduto = (produto) => {
  try {
    const produtos = getProdutos();
    const novoProduto = {
      id: Date.now().toString(), // ID único baseado em timestamp
      ...produto,
      dataCadastro: new Date().toISOString()
    };
    produtos.push(novoProduto);
    localStorage.setItem(STORAGE_KEY, JSON.stringify(produtos));
    return novoProduto;
  } catch (error) {
    console.error('Erro ao salvar produto:', error);
    throw error;
  }
};

// Buscar produto por ID
export const getProdutoPorId = (id) => {
  try {
    const produtos = getProdutos();
    return produtos.find(produto => produto.id === id);
  } catch (error) {
    console.error('Erro ao buscar produto por ID:', error);
    return null;
  }
};

// Limpar todos os produtos (útil para testes)
export const limparProdutos = () => {
  try {
    localStorage.removeItem(STORAGE_KEY);
  } catch (error) {
    console.error('Erro ao limpar produtos:', error);
  }
};