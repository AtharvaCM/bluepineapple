import React from "react";
import { Link } from "react-router-dom";

const AddUserButton = () => {
  return (
    <Link to="/user/add" className="floating-button">
      Add User
    </Link>
  );
};

export default AddUserButton;
