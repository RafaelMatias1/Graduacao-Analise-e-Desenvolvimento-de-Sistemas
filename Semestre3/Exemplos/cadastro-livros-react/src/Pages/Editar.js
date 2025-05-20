import { useEffect, useLayoutEffect, useState } from "react"

import Formulario from "../Components/Formulario";
import { useNavigate, useParams } from "react-router-dom";

const Editar = () => {
    const [livrosSalvos, setLivrosSalvos] = useState([])

    const [nome, setNome] = useState("Julio Cezar")

    const { id } = useParams()

    const navigate = useNavigate()

    function handleNome(event){
        setNome(event.target.value)
    }

    useLayoutEffect(() => {
        console.log("Antes de montar o nome "+nome)
    }, [])

    useEffect(() => {
        console.log("Montou o nome "+nome)
    }, [])

    useEffect(() => {
        console.log("Atualizou o Nome para "+nome)
    }, [nome])

    useEffect(() => {
        console.log("Matou o Nome para "+nome)
        return;
    }, [])



    function handleSubmit(){
        navigate('/cadastro')
    }

    return( <main>
                <section id="campos">
                    <form id="formulario"> 
                        <input onChange={handleNome} className="campos" type="text" name="nome" placeholder="Nome do Livro" /> 
                        <input className="campos" type="text" name="paginas" placeholder="Páginas do Livro" /> 
                        <input className="campos" type="text" name="autor" placeholder="Autor do Livro" />
                        <p id="mensagem_form"></p> 
                        <a onClick={handleSubmit} id="botao_gravar">Salvar</a>
                    </form>
                </section>
                </main>
    )
}

export default Editar;