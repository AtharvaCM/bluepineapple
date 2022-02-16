import "./App.css";
import { Routes, Route } from "react-router-dom";

import Nav from "./Components/NavComponent";
import UserListPage from "./pages/UserListPage";
import UserPage from "./pages/UserPage";

function App() {
  return (
    <div className="App ">
      <Nav />
      <Routes>
        <Route path="/" exact element={<UserListPage />} />
        <Route path="/user/:id" element={<UserPage />} />
      </Routes>
    </div>
  );
}

export default App;
