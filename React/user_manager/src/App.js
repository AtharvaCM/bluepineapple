import "./App.css";
import { Routes, Route } from "react-router-dom";

import UserListPage from "./pages/UserListPage";
import UserPage from "./pages/UserPage";
import Header from "./Components/HeaderComponent";

function App() {
  return (
    <div className="App ">
      <Header />
      <Routes>
        <Route path="/" exact element={<UserListPage />} />
        <Route path="/user/:id" element={<UserPage />} />
        <Route
          path="*"
          element={
            <main style={{ padding: "1rem" }}>
              <p>There's nothing here!</p>
            </main>
          }
        />
      </Routes>
    </div>
  );
}

export default App;
