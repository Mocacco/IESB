import {useState} from "react";
import InputNome from "../components/InputNome.jsx";
import InputTelefone from "../components/InputTelefone.jsx";


function Fomulario(props) {
  const [nome, setNome] = useState("");
  const [erroNome, setErroNome] = useState("");
  const [telefone, setTelefone] = useState("");
  const [erroTelefone, setErroTelefone] = useState("");

  const handleSubmit = (e) => {
    e.preventDefault();

    let valid = true;

    if (!nome) {
      setErroNome("Nome é obrigatório");
      valid = false;
    } else {
      setErroNome("");
    }

    if (!telefone) {
      setErroTelefone("Telefone é obrigatório");
      valid = false;
    } else {
      setErroTelefone("");
    }

    if (valid) {
      props.onSubmit({ nome, telefone });
      setNome("");
      setTelefone("");
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <InputNome
        valor={nome}
        onChange={(e) => setNome(e.target.value)}
        erro={erroNome}
      />
      <InputTelefone
        valor={telefone}
        onChange={(e) => setTelefone(e.target.value)}
        erro={erroTelefone}
      />
      <button type="submit">Salvar</button>
    </form>
    );
    }

    export default Formulario;