import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'
import { RotaProvider } from "./contexts/RotaContext.jsx"

createRoot(document.getElementById('root')).render(
  <RotaProvider>
  <App/>
  </RotaProvider>
)
