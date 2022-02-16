import React from "react";
import { Link } from "react-router-dom";

const Header = () => {
  return (
    <div className="app-header">
      <Link to="/" className="app-header">
        Home
      </Link>
    </div>
  );
};

export default Header;
