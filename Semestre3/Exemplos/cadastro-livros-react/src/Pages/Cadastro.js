import { useEffect, useState } from "react"

import Formulario from "../Components/Formulario";
import Tabela from "../Components/Tabela";

const Cadastro = () => {
    const [livrosSalvos, setLivrosSalvos] = useState([])
    const [post, setPost] = useState([])

    function exec(){
        fetch('https://jsonplaceholder.typicode.com/posts')
            .then(response => response.json())
            .then(data => setPost(data))
            .catch((erro) => {
                console.error("Erro na busca "+erro)
            })    
    }

    useEffect(() => {
        let livros = JSON.parse(localStorage.getItem("livros") || "[]")
        setLivrosSalvos(livros)
        exec()
    }, [])

    return( 
            <main>
                <Formulario livrosSalvos={livrosSalvos} setLivrosSalvos={setLivrosSalvos} />
                <Tabela livrosSalvos={livrosSalvos} />
            </main>
    )
}

export default Cadastro;