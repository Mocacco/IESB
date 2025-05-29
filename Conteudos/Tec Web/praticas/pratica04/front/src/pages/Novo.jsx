import { useContext, useState } from "react";
import { adicionar } from "../services/ContatoService";
import { RotaContext } from "../contexts/RotaContext.jsx";
import Fomulario from "./Formulario.jsx";

function Novo() {
    const [erro, setErro] = useState("");
  const { setRota } = useContext(RotaContext);

  const handleSalvar = async (contato) => {
    const resposta = await adicionar(contato);

    if (resposta.sucesso) {
      setErro("");
      setRota("/listar");
    } else {
      setErro(resposta.mensagem);
    }
  };

  return (
    <>
      <h2>Novo Contato</h2>
      <Formulario onSubmit={handleSalvar} />
      {erro && <p>{erro}</p>}
    </>
    );
    }
    export default Novo;