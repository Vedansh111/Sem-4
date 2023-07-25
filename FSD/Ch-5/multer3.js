var expr = require("express");
var app = expr();
const multer = require("multer");
app.get("/", (req, res) => {
  res.sendFile(__dirname + "/3.html");
});
var store = multer.diskStorage({
  destination: "uploaddd",
  filename: function (req, file, cb) {
    cb(null, file.fieldname + "-" + Date.now() + ".pdf");
  },
});
const filter = (req, file, cb) => {
  if (file.mimetype == "application/pdf") {
    cb(null, true);
  } else {
    cb(null, false);
    return cb("only pdf format allowed");
  }
};
const maxSize = 1024 * 1024 * 1024;
var upload = multer({
  storage: store,
  limits: { fileSize: maxSize },
  fileFilter: filter,
});
// var upload = multer({ storage: store });
app.post("/uploadddfile", upload.single("data"), (req, res) => {
  const file = req.file;
  console.log(file);
  if (file) {
    res.send(
      "<h1>File<span style='color:red'>" +
        file.originalname +
        "</span>'has been uploaded in'" +
        file.destination +
        "'folder'</h1>"
    );
  }
});
app.listen(9010, (req, res) => {
  console.log("Server is running...");
});
