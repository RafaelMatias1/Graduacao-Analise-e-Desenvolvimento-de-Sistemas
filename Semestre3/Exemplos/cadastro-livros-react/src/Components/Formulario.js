import { useEffect, useState } from "react"

const Formulario = (props) => {
    
    const [nome, setNome] = useState("")
    const [paginas, setPaginas] = useState("")
    const [autor, setAutor] = useState("")

    function handleNome(event){
        setNome(event.target.value)
    }
    
    function handleAutor(event){
        setAutor(event.target.value)
    }
    
    function handlePaginas(event){
        setPaginas(event.target.value)
    }

    function handleSubmit(){
        let livro = {
            nome: nome,
            paginas: paginas,
            autor: autor
        }

        props.setLivrosSalvos([...props.livrosSalvos, livro])

        localStorage.setItem("livros", JSON.stringify(props.livrosSalvos))
    }

    return(
        <section id="campos">
                    <form id="formulario"> 
                        <input onChange={handleNome} className="campos" type="text" name="nome" placeholder="Nome do Livro" /> 
                        <input onChange={handlePaginas} className="campos" type="text" name="paginas" placeholder="Páginas do Livro" /> 
                        <input onChange={handleAutor} className="campos" type="text" name="autor" placeholder="Autor do Livro" />
                        <p id="mensagem_form"></p> 
                        <a onClick={handleSubmit} id="botao_gravar">Salvar</a>
                    </form>
                </section>
    )
}

export default Formulario;