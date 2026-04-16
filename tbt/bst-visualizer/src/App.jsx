import { useState, useRef } from "react";

// ═══════════════════════════════════════════════════════════════
//  THREADED BST LOGIC
// ═══════════════════════════════════════════════════════════════

class TNode {
  constructor(v) { this.v = v; this.left = null; this.right = null; this.rTh = false; }
}

function bstInsert(root, val) {
  if (!root) return new TNode(val);
  let cur = root, par = null, goLeft = false;
  for (;;) {
    if (val === cur.v) return root; // duplicate — skip
    par = cur;
    if (val < cur.v) {
      if (!cur.left) { goLeft = true; break; }
      cur = cur.left;
    } else {
      if (cur.rTh || !cur.right) { goLeft = false; break; }
      cur = cur.right;
    }
  }
  const n = new TNode(val);
  if (goLeft) {
    // Insert as left child: thread points to parent (inorder successor)
    n.right = par; n.rTh = true; par.left = n;
  } else {
    // Insert as right child: inherit parent's thread
    n.right = par.right; n.rTh = par.rTh;
    par.right = n; par.rTh = false;
  }
  return root;
}

function bstInorder(root) {
  // O(n) time, O(1) extra space — no stack, no recursion
  if (!root) return [];
  let cur = root;
  while (cur.left) cur = cur.left;
  const res = [];
  while (cur) {
    res.push(cur.v);
    if (cur.rTh) cur = cur.right;                             // follow thread
    else if (cur.right) { cur = cur.right; while (cur.left) cur = cur.left; }
    else break;
  }
  return res;
}

function bstSearch(root, val) {
  const path = [];
  let cur = root;
  while (cur) {
    path.push(cur.v);
    if (cur.v === val) return { found: true, path };
    if (val < cur.v) cur = cur.left;
    else { if (cur.rTh || !cur.right) break; cur = cur.right; }
  }
  return { found: false, path };
}

// ═══════════════════════════════════════════════════════════════
//  SVG LAYOUT
// ═══════════════════════════════════════════════════════════════

const H_GAP = 76, V_GAP = 92, R = 26;

function calcLayout(root) {
  const pos = {};
  let xi = 0;
  function dfs(nd, d) {
    if (!nd) return;
    dfs(nd.left, d + 1);
    pos[nd.v] = { x: xi * H_GAP + R + 14, y: d * V_GAP + R + 14 };
    xi++;
    if (!nd.rTh && nd.right) dfs(nd.right, d + 1); // don't follow threads
  }
  dfs(root, 0);
  return pos;
}

function collectGraph(nd, edges = [], threads = []) {
  if (!nd) return { edges, threads };
  if (nd.left)  { edges.push([nd.v, nd.left.v]);  collectGraph(nd.left, edges, threads); }
  if (nd.right) {
    if (nd.rTh)  threads.push([nd.v, nd.right.v]);
    else         { edges.push([nd.v, nd.right.v]); collectGraph(nd.right, edges, threads); }
  }
  return { edges, threads };
}

function offsetPt(p1, p2, d) {
  const dx = p2.x - p1.x, dy = p2.y - p1.y;
  const len = Math.sqrt(dx * dx + dy * dy) || 1;
  return { x: p1.x + (dx / len) * d, y: p1.y + (dy / len) * d };
}

// ═══════════════════════════════════════════════════════════════
//  COLOR STATES
// ═══════════════════════════════════════════════════════════════

const STATES = {
  inserted: { fill: "#0d9488", stroke: "#14b8a6", glow: true,  text: "#f0fdfa" },
  found:    { fill: "#065f46", stroke: "#10b981", glow: true,  text: "#6ee7b7" },
  visited:  { fill: "#0f766e", stroke: "#0d9488", glow: false, text: "#ccfbf1" },
  active:   { fill: "#92400e", stroke: "#f59e0b", glow: true,  text: "#fde68a" },
  path:     { fill: "#1c1917", stroke: "#d97706", glow: false, text: "#fbbf24" },
  notfound: { fill: "#450a0a", stroke: "#ef4444", glow: true,  text: "#fca5a5" },
  default:  { fill: "#0f172a", stroke: "#334155", glow: false, text: "#64748b" },
};

// ═══════════════════════════════════════════════════════════════
//  SUB-COMPONENTS
// ═══════════════════════════════════════════════════════════════

function Btn({ onClick, color, ghost, children }) {
  const [hov, setHov] = useState(false);
  return (
    <button
      onClick={onClick}
      onMouseEnter={() => setHov(true)}
      onMouseLeave={() => setHov(false)}
      style={{
        background: hov ? color : ghost ? "transparent" : `${color}1a`,
        border: `1.5px solid ${color}`,
        color: hov ? "#060810" : color,
        padding: "9px 20px",
        borderRadius: 6,
        cursor: "pointer",
        fontFamily: "'Courier New', monospace",
        fontSize: "0.76rem",
        fontWeight: "bold",
        letterSpacing: "0.1em",
        transition: "all 0.15s ease",
        userSelect: "none",
        flexShrink: 0,
      }}
    >
      {children}
    </button>
  );
}

function StatusBar({ status }) {
  const colors = { ok: "#14b8a6", error: "#ef4444", idle: "#475569" };
  const c = colors[status.type];
  return (
    <div style={{
      background: "#0a0e1a",
      borderLeft: `3px solid ${c}`,
      borderTop: `1px solid ${c}28`,
      borderRight: `1px solid ${c}28`,
      borderBottom: `1px solid ${c}28`,
      borderRadius: "0 6px 6px 0",
      padding: "8px 14px",
      marginBottom: 12,
      fontSize: "0.8rem",
      color: c,
      letterSpacing: "0.04em",
      transition: "all 0.3s ease",
      minHeight: 36,
      display: "flex",
      alignItems: "center",
    }}>
      {status.msg}
    </div>
  );
}

// ═══════════════════════════════════════════════════════════════
//  MAIN COMPONENT
// ═══════════════════════════════════════════════════════════════

export default function ThreadedBSTViz() {
  const treeRef  = useRef(null);
  const timersRef = useRef([]);
  const [tick,     setTick]     = useState(0);
  const [input,    setInput]    = useState("");
  const [hl,       setHl]       = useState({});
  const [status,   setStatus]   = useState({ msg: "Insert nodes to build the tree", type: "idle" });
  const [travList, setTravList] = useState([]);

  const refresh  = () => setTick(t => t + 1);
  const clearT   = () => { timersRef.current.forEach(clearTimeout); timersRef.current = []; };
  const addT     = (fn, ms) => timersRef.current.push(setTimeout(fn, ms));
  const getInt   = () => { const v = parseInt(input.trim(), 10); return isNaN(v) ? null : v; };

  // ── Handlers ────────────────────────────────────────────────

  function handleInsert() {
    const v = getInt();
    if (v === null) return setStatus({ msg: "⚠  Enter a valid integer", type: "error" });
    clearT(); setTravList([]);
    treeRef.current = bstInsert(treeRef.current, v);
    setHl({ [v]: "inserted" });
    setStatus({ msg: `✦  Inserted ${v}`, type: "ok" });
    setInput(""); refresh();
    addT(() => setHl({}), 1400);
  }

  function handleSearch() {
    const v = getInt();
    if (v === null) return setStatus({ msg: "⚠  Enter a valid integer", type: "error" });
    if (!treeRef.current) return setStatus({ msg: "⚠  Tree is empty", type: "error" });
    clearT(); setTravList([]); setHl({});
    const { found, path } = bstSearch(treeRef.current, v);
    setStatus({ msg: `Searching for ${v}...`, type: "idle" });
    path.forEach((node, i) => {
      addT(() => {
        setHl(() => {
          const nxt = {};
          path.slice(0, i).forEach(pv => { nxt[pv] = "path"; });
          nxt[node] = i === path.length - 1 ? (found ? "found" : "notfound") : "active";
          return nxt;
        });
        if (i === path.length - 1)
          setStatus({ msg: found ? `✓  Found ${v}` : `✗  ${v} not found in tree`, type: found ? "ok" : "error" });
      }, i * 580);
    });
  }

  function handleInorder() {
    if (!treeRef.current) return setStatus({ msg: "⚠  Tree is empty", type: "error" });
    clearT();
    const ord = bstInorder(treeRef.current);
    setHl({}); setTravList([]);
    setStatus({ msg: "Running inorder traversal using threads...", type: "idle" });
    ord.forEach((v, i) => {
      addT(() => {
        setHl(() => {
          const nxt = {};
          ord.slice(0, i).forEach(pv => { nxt[pv] = "visited"; });
          nxt[v] = "active";
          return nxt;
        });
        setTravList(ord.slice(0, i + 1));
        if (i === ord.length - 1) {
          setStatus({ msg: `Inorder: ${ord.join(" → ")}`, type: "ok" });
          addT(() => setHl(() => { const f = {}; ord.forEach(pv => f[pv] = "found"); return f; }), 500);
        }
      }, i * 620);
    });
  }

  function handleClear() {
    clearT(); treeRef.current = null;
    setHl({}); setTravList([]); setInput("");
    setStatus({ msg: "Tree cleared", type: "idle" });
    refresh();
  }

  // ── SVG Computations ─────────────────────────────────────────
  const pos = calcLayout(treeRef.current);
  const { edges, threads } = collectGraph(treeRef.current);
  const allP = Object.values(pos);
  const svgW = allP.length ? Math.max(...allP.map(p => p.x)) + R + 28 : 300;
  const svgH = allP.length ? Math.max(...allP.map(p => p.y)) + R + 28 : 160;
  const sc   = v => STATES[hl[v]] || STATES.default;
  const nodeCount = allP.length;

  // ── Render ───────────────────────────────────────────────────
  return (
    <div style={{
      background: "#060810",
      minHeight: "100vh",
      fontFamily: "'Courier New', monospace",
      color: "#e2e8f0",
      padding: "28px 22px",
      boxSizing: "border-box",
    }}>

      {/* Header */}
      <div style={{ marginBottom: 22 }}>
        <div style={{ display: "flex", alignItems: "center", gap: 10, marginBottom: 6 }}>
          <svg width="16" height="16" viewBox="0 0 16 16">
            <circle cx="8" cy="8" r="6.5" fill="none" stroke="#14b8a6" strokeWidth="1.5"/>
            <circle cx="8" cy="8" r="3" fill="#14b8a6"/>
          </svg>
          <span style={{ fontSize: "1.05rem", color: "#14b8a6", fontWeight: "bold", letterSpacing: "0.14em" }}>
            RIGHT-THREADED BST VISUALIZER
          </span>
          {nodeCount > 0 && (
            <span style={{
              background: "#14b8a618", border: "1px solid #14b8a644",
              color: "#14b8a6", fontSize: "0.68rem", padding: "2px 8px",
              borderRadius: 4, letterSpacing: "0.06em", marginLeft: 6,
            }}>
              {nodeCount} NODE{nodeCount !== 1 ? "S" : ""}
            </span>
          )}
        </div>
        <p style={{ color: "#1e3a5f", fontSize: "0.68rem", margin: 0, letterSpacing: "0.07em", paddingLeft: 26 }}>
          NULL RIGHT POINTERS → INORDER SUCCESSOR THREADS ( ╌╌▶ ) · O(1) SPACE TRAVERSAL
        </p>
      </div>

      {/* Controls */}
      <div style={{ display: "flex", flexWrap: "wrap", gap: 10, marginBottom: 14, alignItems: "center" }}>
        <input
          type="number"
          value={input}
          onChange={e => setInput(e.target.value)}
          onKeyDown={e => e.key === "Enter" && handleInsert()}
          placeholder="value..."
          style={{
            background: "#0a0e1a",
            border: "1.5px solid #1e3a5f",
            color: "#e2e8f0",
            padding: "9px 14px",
            borderRadius: 6,
            fontFamily: "inherit",
            fontSize: "0.88rem",
            width: 130,
            outline: "none",
          }}
        />
        <Btn onClick={handleInsert} color="#14b8a6">INSERT</Btn>
        <Btn onClick={handleSearch} color="#f59e0b">SEARCH</Btn>
        <Btn onClick={handleInorder} color="#a78bfa">INORDER</Btn>
        <Btn onClick={handleClear} color="#ef4444" ghost>CLEAR</Btn>
      </div>

      {/* Status bar */}
      <StatusBar status={status} />

      {/* Traversal output */}
      {travList.length > 0 && (
        <div style={{
          background: "#0a0e1a",
          border: "1px solid #4c1d9533",
          borderRadius: 6,
          padding: "8px 14px",
          marginBottom: 14,
          fontSize: "0.79rem",
          letterSpacing: "0.04em",
          overflowX: "auto",
          whiteSpace: "nowrap",
        }}>
          <span style={{ color: "#334155" }}>INORDER: </span>
          {travList.map((v, i) => (
            <span key={i}>
              <span style={{ color: hl[v] ? sc(v).stroke : "#8b5cf6", transition: "color 0.3s" }}>{v}</span>
              {i < travList.length - 1 && <span style={{ color: "#1e293b" }}> → </span>}
            </span>
          ))}
        </div>
      )}

      {/* SVG Tree Canvas */}
      <div style={{
        background: "#040609",
        border: "1px solid #0f172a",
        borderRadius: 14,
        padding: "20px",
        overflowX: "auto",
        overflowY: "auto",
        minHeight: 220,
        maxHeight: 520,
        position: "relative",
      }}>
        {/* Dot-grid background */}
        <div style={{
          position: "absolute", inset: 0, borderRadius: 14, overflow: "hidden",
          backgroundImage: "radial-gradient(#0f172a 1.5px, transparent 1.5px)",
          backgroundSize: "28px 28px",
          pointerEvents: "none",
        }} />

        {!treeRef.current ? (
          <div style={{
            color: "#0f172a", textAlign: "center", padding: "70px 20px",
            fontSize: "0.82rem", letterSpacing: "0.1em", position: "relative",
          }}>
            [ TREE EMPTY — INSERT SOME NODES ]
          </div>
        ) : (
          <svg
            width={Math.max(svgW, 280)}
            height={Math.max(svgH, 160)}
            style={{ display: "block", position: "relative", overflow: "visible" }}
          >
            <defs>
              <marker id="tharrow" markerWidth="9" markerHeight="9" refX="7" refY="3.5" orient="auto">
                <path d="M0,0 L0,7 L8,3.5 Z" fill="#7c3aed" />
              </marker>
            </defs>

            {/* Regular tree edges */}
            {edges.map(([a, b], i) => {
              const p1 = pos[a], p2 = pos[b];
              if (!p1 || !p2) return null;
              const s = offsetPt(p1, p2, R + 3);
              const e = offsetPt(p2, p1, R + 3);
              return (
                <line key={`e${i}`}
                  x1={s.x} y1={s.y} x2={e.x} y2={e.y}
                  stroke="#0f2744" strokeWidth="2.5"
                />
              );
            })}

            {/* Thread pointer arrows */}
            {threads.map(([a, b], i) => {
              const p1 = pos[a], p2 = pos[b];
              if (!p1 || !p2) return null;
              // Control point curves to the right of both nodes
              const cx = Math.max(p1.x, p2.x) + 58;
              const cy = (p1.y + p2.y) / 2;
              // Start: offset from p1 circle in direction of control pt
              const dx0 = cx - p1.x, dy0 = cy - p1.y;
              const l0  = Math.sqrt(dx0*dx0 + dy0*dy0) || 1;
              const sx  = p1.x + (dx0/l0) * (R + 3);
              const sy  = p1.y + (dy0/l0) * (R + 3);
              // End: offset from p2 circle back toward control pt
              const dx1 = p2.x - cx, dy1 = p2.y - cy;
              const l1  = Math.sqrt(dx1*dx1 + dy1*dy1) || 1;
              const ex  = p2.x - (dx1/l1) * (R + 8);
              const ey  = p2.y - (dy1/l1) * (R + 8);
              return (
                <path key={`th${i}`}
                  d={`M ${sx} ${sy} Q ${cx} ${cy} ${ex} ${ey}`}
                  stroke="#7c3aed" strokeWidth="1.5"
                  fill="none" strokeDasharray="5 3"
                  markerEnd="url(#tharrow)"
                  opacity="0.75"
                />
              );
            })}

            {/* Nodes */}
            {Object.entries(pos).map(([vStr, { x, y }]) => {
              const v = parseInt(vStr, 10);
              const c = sc(v);
              return (
                <g key={v}>
                  {c.glow && (
                    <circle cx={x} cy={y} r={R + 8} fill={c.stroke} opacity="0.15" />
                  )}
                  <circle
                    cx={x} cy={y} r={R}
                    fill={c.fill}
                    stroke={c.stroke}
                    strokeWidth="2"
                    style={{ transition: "fill 0.35s ease, stroke 0.35s ease" }}
                  />
                  <text
                    x={x} y={y}
                    textAnchor="middle"
                    dominantBaseline="central"
                    fill={c.text}
                    fontSize="13"
                    fontWeight="bold"
                    fontFamily="'Courier New', monospace"
                    style={{ transition: "fill 0.35s ease", userSelect: "none" }}
                  >
                    {v}
                  </text>
                </g>
              );
            })}
          </svg>
        )}
      </div>

      {/* Legend */}
      <div style={{
        display: "flex", flexWrap: "wrap",
        gap: "10px 22px", marginTop: 16,
        fontSize: "0.67rem", color: "#334155", letterSpacing: "0.07em",
      }}>
        {[
          { color: "#0f2744", label: "TREE EDGE",       dashed: false, arrow: false },
          { color: "#7c3aed", label: "THREAD POINTER",  dashed: true,  arrow: true  },
          { color: "#14b8a6", label: "INSERTED / FOUND",dashed: false, arrow: false },
          { color: "#d97706", label: "SEARCH PATH",     dashed: false, arrow: false },
          { color: "#f59e0b", label: "CURRENT NODE",    dashed: false, arrow: false },
          { color: "#ef4444", label: "NOT FOUND",       dashed: false, arrow: false },
        ].map(({ color, label, dashed, arrow }) => (
          <div key={label} style={{ display: "flex", alignItems: "center", gap: 7 }}>
            <svg width="28" height="12" style={{ flexShrink: 0 }}>
              <line x1="0" y1="6" x2={arrow ? "20" : "28"} y2="6"
                stroke={color} strokeWidth={dashed ? "1.5" : "2.5"}
                strokeDasharray={dashed ? "5 3" : undefined}
              />
              {arrow && <polygon points="18,3 26,6 18,9" fill={color} />}
            </svg>
            {label}
          </div>
        ))}
      </div>

      {/* Info panel */}
      <div style={{
        marginTop: 20,
        background: "#0a0e1a",
        border: "1px solid #0f172a",
        borderRadius: 8,
        padding: "12px 16px",
        fontSize: "0.71rem",
        color: "#334155",
        letterSpacing: "0.05em",
        lineHeight: 1.75,
      }}>
        <span style={{ color: "#7c3aed" }}>▶ WHAT IS A RIGHT-THREADED BST?  </span>
        Each node whose right child is null has its right pointer replaced by a thread pointing to its inorder
        successor. Inorder traversal uses{" "}
        <span style={{ color: "#14b8a6" }}>O(1) extra space</span> — just follow left links until the
        leftmost node, then alternate: visit → follow thread or go right. No stack, no recursion.
      </div>
    </div>
  );
}
