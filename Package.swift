// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterNelua",
    products: [
        .library(name: "TreeSitterNelua", targets: ["TreeSitterNelua"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterNelua",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                // NOTE: if your language has an external scanner, add it here.
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterNeluaTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterNelua",
            ],
            path: "bindings/swift/TreeSitterNeluaTests"
        )
    ],
    cLanguageStandard: .c11
)
