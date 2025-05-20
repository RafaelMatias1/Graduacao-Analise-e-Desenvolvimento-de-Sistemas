import React, { useState } from 'react'

function ContadorFuncao () {
    const [count, setCount] = useState(0)
    const [titulo, setTitulo] = useState("")

    const increment = () => {
        setCount(count + 1)
    }

    return(
            <div>
                <h2>Contador: {count}</h2>
                <button onClick={increment}>Incrementar</button>
            </div>
    )
    

}

export default ContadorFuncao;