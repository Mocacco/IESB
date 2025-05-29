import { useContext } from "react";
import { RotaContext } from "./contexts/RotaContext.jsx";
import Cabecalho from "./components/Cabecalho.jsx";
import Conteudo from "./components/Conteudo.jsx";
import Listar from "./pages/listar.jsx";
import Novo from "./pages/Novo.jsx";
import Editar from "./pages/Editar.jsx";

function App() {
  return (
  <>
  const { setRota } = useContext(RotaContext);
  <Cabecalho />
  <Conteudo>
    {rota === "/listar" && <Listar />}
    {rota === "/novo" && <Novo />}
    {rota.substr(0, 7) === "/editar" && <Editar />}
  </Conteudo>
  </>
  );
  }
  export default App;