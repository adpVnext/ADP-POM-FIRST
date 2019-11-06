cordova.define('cordova/plugin_list', function(require, exports, module) {
  module.exports = [
    {
      "id": "cordova-plugin-sqlite.SQLitePlugin",
      "file": "plugins/cordova-plugin-sqlite/www/SQLitePlugin.js",
      "pluginId": "cordova-plugin-sqlite",
      "clobbers": [
        "window.sqlitePlugin",
        "cordova.plugins.sqlitePlugin"
      ]
    },
    {
      "id": "cordova-plugin-statusbar.statusbar",
      "file": "plugins/cordova-plugin-statusbar/www/statusbar.js",
      "pluginId": "cordova-plugin-statusbar",
      "clobbers": [
        "window.StatusBar"
      ]
    },
    {
      "id": "cordova-plugin-app-preferences.apppreferences",
      "file": "plugins/cordova-plugin-app-preferences/www/apppreferences.js",
      "pluginId": "cordova-plugin-app-preferences",
      "clobbers": [
        "plugins.appPreferences"
      ]
    },
    {
      "id": "cordova-plugin-geolocation.Coordinates",
      "file": "plugins/cordova-plugin-geolocation/www/Coordinates.js",
      "pluginId": "cordova-plugin-geolocation",
      "clobbers": [
        "Coordinates"
      ]
    },
    {
      "id": "cordova-plugin-geolocation.PositionError",
      "file": "plugins/cordova-plugin-geolocation/www/PositionError.js",
      "pluginId": "cordova-plugin-geolocation",
      "clobbers": [
        "PositionError"
      ]
    },
    {
      "id": "cordova-plugin-geolocation.Position",
      "file": "plugins/cordova-plugin-geolocation/www/Position.js",
      "pluginId": "cordova-plugin-geolocation",
      "clobbers": [
        "Position"
      ]
    },
    {
      "id": "cordova-plugin-geolocation.geolocation",
      "file": "plugins/cordova-plugin-geolocation/www/geolocation.js",
      "pluginId": "cordova-plugin-geolocation",
      "clobbers": [
        "navigator.geolocation"
      ]
    },
    {
      "id": "fr.aeroportsdeparis.cordova.pom.POM",
      "file": "plugins/fr.aeroportsdeparis.cordova.pom/www/pom.js",
      "pluginId": "fr.aeroportsdeparis.cordova.pom",
      "clobbers": [
        "pomPlugin"
      ]
    },
    {
      "id": "fr.aeroportdeparis.Barcodescanner.BARCOD",
      "file": "plugins/fr.aeroportdeparis.Barcodescanner/www/barcodescanner.js",
      "pluginId": "fr.aeroportdeparis.Barcodescanner",
      "clobbers": [
        "BarcodeScanner"
      ]
    }
  ];
  module.exports.metadata = {
    "cordova-plugin-sqlite": "1.0.3",
    "cordova-plugin-statusbar": "2.4.2",
    "cordova-plugin-app-preferences": "0.99.3",
    "cordova-plugin-geolocation": "4.0.1",
    "fr.aeroportsdeparis.cordova.pom": "1.8.3",
    "fr.aeroportdeparis.Barcodescanner": "1.8.3"
  };
});