/* eslint-disable react-hooks/exhaustive-deps */
import React, { useState, useEffect } from "react";
import { useParams } from "react-router-dom";

const UserPage = () => {
  let params = useParams();
  console.log("params", params);
  let userId = params.id;

  let [user, setUser] = useState({});

  useEffect(() => {
    getUser();
  }, []);

  let getUser = () => {
    let response = require("../api/users.json");
    let data = response.find((user) => user.id === userId);
    console.log("get user data", data);
    setUser(data);
  };

  return (
    <div className="user-page-container container d-flex justify-content-center align-items-center">
      <div className="card">
        <img
          src={user.avatar_url}
          className="card-img-top"
          alt={user.name}
          height="300"
          width="300"
        />
        <div className="card-body">
          <h5 className="card-title">{user.name}</h5>
        </div>
        <ul className="list-group list-group-flush">
          <li className="list-group-item">
            <strong>Email:</strong> {user.email}
          </li>
          <li className="list-group-item">
            <strong>Mobile:</strong> {user.mobile}
          </li>
        </ul>
      </div>
    </div>
  );
};

export default UserPage;
