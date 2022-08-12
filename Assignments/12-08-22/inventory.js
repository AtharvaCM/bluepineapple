// {
//   partNo: number,
//   price: number,
//   locations: {locationId: number, locationName: string, quantity: number}[],
// }

const PART_PRICE = [
  {
    p_no: 100,
    price: 2,
  },
  {
    p_no: 101,
    price: 5,
  },
  {
    p_no: 102,
    price: 10,
  },
  {
    p_no: 103,
    price: 3,
  },
];

const LOC_PART_QTY = [
  {
    loc_id: 121,
    p_no: 100,
    qty: 5,
  },
  {
    loc_id: 122,
    p_no: 101,
    qty: 12,
  },
  {
    loc_id: 123,
    p_no: 102,
    qty: 8,
  },
  {
    loc_id: 121,
    p_no: 103,
    qty: 15,
  },
  {
    loc_id: 122,
    p_no: 100,
    qty: 50,
  },
  {
    loc_id: 123,
    p_no: 100,
    qty: 33,
  },
  {
    loc_id: 121,
    p_no: 102,
    qty: 47,
  },
];

const LOC_ID_NAME = [
  {
    loc_id: 121,
    loc_name: "ABC",
  },
  {
    loc_id: 122,
    loc_name: "XYZ",
  },
  {
    loc_id: 123,
    loc_name: "PQR",
  },
];

// helper function to get location name from location id, returns a string
const getLocationName = (locationId) => {
  const location = LOC_ID_NAME.find((loc) => loc.loc_id === locationId);
  return location.loc_name;
};

// helper function to get locations of a part, returns array of locations
const getLocations = (partNo) => {
  if (!partNo || isNaN(partNo)) {
    console.log("Inavlid part number");
    return;
  }

  const locations = LOC_PART_QTY.filter((loc) => loc.p_no === partNo);
  const locationsWithName = locations.map((loc) => {
    // append loc_name for correspongind loc_id
    return {
      ...loc,
      loc_name: getLocationName(loc.loc_id),
    };
  });

  return locationsWithName;
};

const invMap = new Map();

// for every part, store info for that map
PART_PRICE.forEach((part) => {
  // construct object to insert in map
  const mapValue = {
    p_no: part.p_no,
    price: part.price,
    locations: getLocations(+part.p_no),
  };

  // add object to Map
  invMap.set(part.p_no, mapValue);

  console.log("mapValue: ", mapValue);
});
