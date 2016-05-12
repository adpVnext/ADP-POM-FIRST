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
    }
];
module.exports.metadata = 
// TOP OF METADATA
{
    "org.apache.cordova.statusbar": "0.1.8",
    "fr.aeroportsdeparis.cordova.pom": "1.6.3"
}
// BOTTOM OF METADATA
});