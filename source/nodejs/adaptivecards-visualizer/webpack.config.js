var webpack = require("webpack");
var path = require("path");
var monacoWebpack = require('monaco-editor-webpack-plugin');

var visualizer = {
    devtool: "source-map",
    entry: {
        "adaptivecards-visualizer": ["./src/app.ts"],
        "adaptivecards-visualizer.min": ["./src/app.ts"]
    },
    output: {
        path: path.resolve(__dirname, "dist"),
        filename: "[name].js",
    },
    resolve: {
        extensions: [".ts", ".tsx", ".js", ".css"]
    },
    plugins: [
        new monacoWebpack(
            {
                languages: ["json"]
            }
        )
    ],
    optimization: {},
    module: {
        rules: [
            {
                test: /\.ts$/,
                loader: "ts-loader"
            },
            {
                test: /\.css$/,
                loader: "css-loader"
            },
            {
                test: /\.json$/,
                loader: "json-loader",
            }
        ]
    },
    externals: {
        "adaptivecards": { var: "AdaptiveCards" },
        "markdown-it": { var: "markdownit"}
    }
};

module.exports = visualizer;
