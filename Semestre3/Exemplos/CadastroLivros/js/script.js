window.onload = function(){

    let livro = null

    const botaoSalvar = document.getElementById("botao_gravar")
    
    botaoSalvar.addEventListener("click", salvarLivro)

    const formulario = document.getElementById("formulario")
    const tabela = document.getElementById("body_tabela")

    function salvarLivro(){
        let camposVazios = "";

        const linha = document.createElement("div")
        linha.setAttribute("class", "livro")

        for(let i = 0; i < formulario.children.length; i++){
            console.log(livro)
            
            let type = formulario.children[i].getAttribute("type");

            if(type == "text"){
                if(livro == null){
                    if(formulario.children[i].value == ""){
                        camposVazios += `${formulario.children[i].name}, `;
                    } else {
                        let campo = document.createElement("div")
                        campo.innerHTML = formulario.children[i].value
                        campo.setAttribute("class", formulario.children[i].name)
    
                        linha.appendChild(campo)
                    }
                } else {
                    livro.getElementsByClassName(formulario.children[i].name)[0]
                                                .innerHTML = formulario.children[i].value
                }
            }
            
        }

        let mensagem = document.getElementById("mensagem_form")

        if(camposVazios != ""){
            camposVazios = camposVazios.trim();
            camposVazios = camposVazios.substring(0, camposVazios.length-1)
            mensagem.innerHTML = `Os campos ${camposVazios} estão vazios!`
        } else if(livro == null) {
            let acoes = document.createElement("div")
            acoes.setAttribute("class", "acoes")
            let btnExcluir = document.createElement("a")
            btnExcluir.innerHTML = "Excluir"
            btnExcluir.addEventListener("click", excluirLivro)

            let btnAlterar = document.createElement("a")
            btnAlterar.innerHTML = "Alterar"
            btnAlterar.addEventListener("click", alterarCampos)

            acoes.appendChild(btnExcluir)
            acoes.appendChild(btnAlterar)

            linha.appendChild(acoes)

            tabela.appendChild(linha)
            formulario.reset()
        } else {
            formulario.reset()
            livro = null
        }
    }

    function excluirLivro(){
        tabela.removeChild(this.parentNode.parentNode)
    }

    function alterarCampos(){
        livro = this.parentNode.parentNode
        for(let i = 0; i < formulario.children.length; i++){
            let type = formulario.children[i].getAttribute("type")

            if(type == "text"){
                let value = livro.getElementsByClassName(formulario.children[i].name)[0].innerHTML

                formulario.children[i].value = value
            }
        }
    }
}

let lista_livros = JSON.parse(localStorage.getItem("livros") || '[]')

let objLivro = {
    "nome": "Teste",
    "paginas": 4,
    "autor": "teste"
}

lista_livros.push(objLivro)

localStorage.setItem("livros", JSON.stringify(lista_livros))