import React from "react";
import { Link } from "react-router-dom";

let getName = (user) => {
  return user.name;
};

let getEmail = (user) => {
  return user.email;
};

let getMobile = (user) => {
  return user.mobile;
};

const ListItem = ({ user }) => {
  return (
    <tr>
      <td>
        <Link to={`/user/${user.id}`}>
          <h6>{getName(user)}</h6>
        </Link>
      </td>
      <td>{getEmail(user)}</td>
      <td>{getMobile(user)}</td>
      <td>
        <Link to={`/user/edit/${user.id}`}>Edit</Link>
      </td>
      <td>
        <Link to={`/user/delete/${user.id}`} className="button-danger">
          Delete
        </Link>
      </td>
    </tr>
  );
};

export default ListItem;
