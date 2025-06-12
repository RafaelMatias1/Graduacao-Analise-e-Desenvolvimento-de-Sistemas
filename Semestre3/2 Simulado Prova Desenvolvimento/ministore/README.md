# MiniStore

MiniStore é uma aplicação web de catálogo de produtos, desenvolvida como um projeto de simulado para provas de desenvolvimento. O sistema permite visualizar, cadastrar e consultar produtos, com dados persistidos no navegador via `localStorage`. A interface é uma Single Page Application (SPA) desenvolvida em React, com navegação fluida e layout organizado.

---

## 📸 Visual do Projeto

![Home MiniStore](./screenshot-home.png)

---

## 🧑‍💻 Funcionalidades

- **Página Inicial:** Mensagem de boas-vindas, descrição da loja e links para navegação.
- **Cadastro de Produtos:** Formulário para adicionar novos produtos (nome, preço, descrição opcional). Dados salvos no localStorage.
- **Listagem de Produtos:** Exibe todos os produtos cadastrados, mostra nome e preço. Exibe total de produtos e permite ver detalhes.
- **Detalhes do Produto:** Exibe nome, preço e descrição completos. Apresenta logs de montagem e desmontagem no console.

---

## 🛠️ Instalação do Projeto

### Pré-requisitos

- [Node.js](https://nodejs.org/) (Recomendado: versão 18.x ou superior)
- [npm](https://www.npmjs.com/) (geralmente já vem com o Node.js)

### Passos para rodar o projeto

1. **Clone este repositório:**

   ```bash
   git clone https://github.com/SEU_USUARIO/ministore.git
   cd ministore
   ```

2. **Instale o React e as dependências do projeto:**

   > Caso queira criar do zero, rode:
   > ```bash
   > npx create-react-app ministore
   > cd ministore
   > ```

   No projeto baixado, rode:
   ```bash
   npm install
   ```

   Isso instala todas as dependências, incluindo:
   - `react`
   - `react-dom`
   - `react-router-dom` (para navegação de páginas)
   npm install react-router-dom 
   - Outras dependências do `package.json`

3. **Rode o projeto:**

   ```bash
   npm start
   ```

   O app abrirá automaticamente em [http://localhost:3000](http://localhost:3000).

---

## 🗂️ Estrutura dos Principais Arquivos

```
ministore/
│
├── public/
├── src/
│   ├── components/
│   │   ├── Header.js
│   │   ├── Header.css
│   │   ├── Footer.js
│   │   └── Footer.css
│   ├── pages/
│   │   ├── Home.js
│   │   ├── Home.css
│   │   ├── CadastroProduto.js
│   │   ├── CadastroProduto.css
│   │   ├── ListagemProdutos.js
│   │   ├── ListagemProdutos.css
│   │   ├── DetalhesProduto.js
│   │   └── DetalhesProduto.css
│   ├── utils/
│   │   └── localStorage.js
│   ├── App.js
│   ├── App.css
│   ├── index.js
│   └── index.css
├── package.json
└── README.md
```

---

## 💾 Como funciona o localStorage

- Todos os produtos cadastrados são salvos no navegador do usuário usando o `localStorage` com a chave `ministore_produtos`.
- Ao cadastrar, listar ou ver detalhes, a aplicação lê e escreve direto no localStorage.
- Não há backend: todos os dados ficam somente no navegador.

---

## 🛣️ Navegação SPA

- O projeto usa o `react-router-dom` para navegação entre páginas **sem recarregar** a aplicação.
- As rotas principais são:
  - `/` — Home
  - `/produtos` — Listagem de Produtos
  - `/cadastro` — Cadastro de Produtos
  - `/produto/:id` — Detalhes do Produto

---

## 🧩 Componentização

- **Header:** Com barra de navegação fixa, logo e links para as páginas principais.
- **Footer:** Com informações fictícias da loja.
- **Pages:** Cada página (home, cadastro, listagem, detalhes) é um componente separado.

---

## 🪝 Hooks e ciclo de vida

- **useState:** Para gerenciar estados dos formulários e listas.
- **useEffect:** Usado para ciclo de vida (montagem/desmontagem), especialmente na página de detalhes, que faz `console.log('Produto carregado!')` ao entrar e `console.log('Saindo da página de detalhes.')` ao sair.
- **useNavigate / useParams:** Para navegação e busca de parâmetros da URL.

---

## 🖌️ Layout e Responsividade

- O layout é responsivo e adaptado para celulares e desktops.
- O design segue o modelo da imagem enviada: header roxo, título destacado, página centralizada e links bem visíveis.

---

## 📚 Dicas para Estudo e Prova

- Entenda como funciona o ciclo de vida dos componentes com `useEffect`.
- Pratique a manipulação do `localStorage` (JSON parse/stringify).
- Revise como fazer navegação SPA com `react-router-dom`.
- Compreenda a componentização: separar responsabilidades entre componentes/páginas.

---

## 📝 Notas Finais

- Este projeto não possui backend. Todos os dados ficam no navegador do usuário.
- Para "resetar" os produtos, limpe o localStorage pelo devtools do navegador.
- Sinta-se à vontade para melhorar o layout e adicionar novas funcionalidades!

---

**Desenvolvido por [Seu Nome] — Simulado de Prova de Desenvolvimento**
