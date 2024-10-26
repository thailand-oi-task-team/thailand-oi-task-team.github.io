import { defineConfigWithTheme } from "vitepress";
import type { ThemeConfig } from "vitepress-carbon";
import baseConfig from "vitepress-carbon/config";

// https://vitepress.dev/reference/site-config
export default defineConfigWithTheme<ThemeConfig>({
  extends: baseConfig,
  title: "ThailandOI",
  description: "ThailandOI task team website",
  srcDir: "src",
  lastUpdated: true,
  cleanUrls: true,
  metaChunk: true,
  // base: "/",

  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: "Home", link: "/" },
      { text: "Materials", link: "/materials/" },
      { text: "Exams", link: "/exams/" },
    ],

    search: {
      provider: "local",
    },

    outline: [2, 3],

    sidebar: [
      {
        text: "Materials",
        items: [
          { text: "ค่ายตุลา 67 (oct67)", link: "/materials/oct67" },
          { text: "ค่ายมีนา 67 (mar67)", link: "/materials/mar67" },
          { text: "ค่ายตุลา 66 (oct66)", link: "/materials/oct66" },
          { text: "ค่ายตุลา 65 (oct65)", link: "/materials/oct65" },
        ],
      },
      {
        text: "Exams",
        items: [
          { text: "ค่ายตุลา 66 (oct66)", link: "/exams/oct66" },
          { text: "ค่ายมีนา 67 (mar67)", link: "/exams/mar67" },
          { text: "ค่ายพฤษภา 67 (may67)", link: "/exams/may67" },
        ],
      },
      {
        text: "About",
        items: [
          { text: "About", link: "/about/" },
          { text: "People", link: "/about/people" },
        ],
      },
    ],

    socialLinks: [
      {
        icon: "github",
        link: "https://github.com/thailand-oi-task-team/thailand-oi-task-team.github.io",
      },
    ],

    lastUpdated: {
      formatOptions: { dateStyle: "short", timeStyle: "short" },
    },

    logo: {
      src: "/logo.png",
    },
  },
  head: [
    [
      "link",
      {
        rel: "icon",
        href: "https://thailand-oi-task-team.github.io/logo.png",
      },
    ],
  ],
  ignoreDeadLinks: true,
});
