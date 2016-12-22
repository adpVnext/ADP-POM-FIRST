cordova.define('cordova/plugin_list', function(require, exports, module) {
               module.exports = [
                                 {
                                 "file": "plugins/org.apache.cordova.statusbar/www/statusbar.js",
                                 "id": "org.apache.cordova.statusbar.statusbar",
                                 "clobbers": [
                                              "window.StatusBar"
                                              ]
                                 },
                                 {
                                 "file": "plugins/fr.aeroportsdeparis.cordova.pom/www/pom.js",
                                 "id": "fr.aeroportsdeparis.cordova.pom.POM",
                                 "clobbers": [
                                              "pomPlugin"
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
                                 "id": "cordova-plugin-sqlite.SQLitePlugin",
                                 "file": "plugins/cordova-plugin-sqlite/www/SQLitePlugin.js",
                                 "pluginId": "cordova-plugin-sqlite",
                                 "clobbers": [
                                              "window.sqlitePlugin",
                                              "cordova.plugins.sqlitePlugin"
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
                                 "id": "cordova-plugin-console.logger",
                                 "file": "plugins/cordova-plugin-console/www/logger.js",
                                 "pluginId": "cordova-plugin-console",
                                 "clobbers": [
                                              "cordova.logger"
                                              ]
                                 }
                                 
                                 ];
               
               module.exports.metadata = 
               // TOP OF METADATA
               {
               "org.apache.cordova.statusbar": "0.1.8",
               "fr.aeroportsdeparis.cordova.pom": "1.6.3",
               "cordova-plugin-compat": "1.1.0",
               "cordova-plugin-geolocation": "2.4.1",
               "cordova-plugin-sqlite": "1.0.3",
               "cordova-plugin-app-preferences": "0.99.3",
               "cordova-plugin-console": "1.0.5",

               
               }
               // BOTTOM OF METADATA
               });
