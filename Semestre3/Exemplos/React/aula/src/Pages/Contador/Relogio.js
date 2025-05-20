import { useState } from "react"

const Relogio = () => {
    const [horario, setHorario] = useState(new Date())
    const [texto, setTexto] = useState("")

    const alterarHorario = () => {
        setHorario(new Date())
    }

    const handleTexto = (event) => {
        setTexto(event.target.value)
    }

    setInterval(function () {
        alterarHorario()
    }, 1000);


    return(
        <div>
            <h2>{texto} - Agora a Hora é {horario.toLocaleTimeString()} </h2>
            <input type="text" onChange={handleTexto} placeholder="Informe Qualquer Coisa" />
        </div>
    )
}

export default Relogio;